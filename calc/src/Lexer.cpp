/*************************************************************************
	> File Name: Lexer.cpp
	> Author: fanpeng
	> Mail: fanpeng@loongson.cn 
	> Created Time: 2023年04月18日 星期二 22时56分36秒
 ************************************************************************/

#include "Lexer.h"

namespace charInfo {
	LLVM_READNONE inline bool isWhiteSpace(char c) {
		return c == ' ' || c == '\t' || c == '\f' ||
			   c == '\v'|| c == '\r' || c == '\n';
	}

	LLVM_READNONE inline bool isDigit(char c) {
		return c >= '0' && c <= '9';
	}

	LLVM_READNONE inline bool isLetter(char c) {
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}
}

void Lexer::next(Token &token) {
	while (*BufferPtr && charInfo::isWhiteSpace(*BufferPtr)) {
		++BufferPtr;
	}
	if (!*BufferPtr) {
		token.Kind = Token::eoi;
		return;
	}
	if (charInfo::isLetter(*BufferPtr)) {
		const char *end = BufferPtr + 1;
		while (charInfo::isLetter(*end)) {
			++end;
		}
		llvm::StringRef Name(BufferPtr, end - BufferPtr);
		Token::TokenKind kind = 
				Name == "with" ? Token::KW_with : Token::ident;

		formToken(token, end, kind);
		return;
	} else if (charInfo::isDigit(*BufferPtr)) {
		const char *end = BufferPtr + 1;
		while (charInfo::isDigit(*end)) {
			++end;
		}

		formToken(token, end, Token::number);
		return;
	} else {
		switch (*BufferPtr) {
#define CASE(ch, tok) \
	case ch: formToken(token, BufferPtr + 1, tok); break
		 CASE('+', Token::plus);
		 CASE('-', Token::minus);
		 CASE('*', Token::star);
		 CASE('/', Token::slash);
		 CASE('(', Token::l_paren);
		 CASE(')', Token::r_paren);
		 CASE(':', Token::colon);
		 CASE(',', Token::comma);
#undef CASE
	default:
		 formToken(token, BufferPtr + 1, Token::unknown);
		}

		return;
	}
}

void Lexer::formToken(Token &tok, const char *tokEnd, Token::TokenKind Kind) {
	tok.Kind = Kind;
	tok.Text = llvm::StringRef(BufferPtr, tokEnd - BufferPtr);
	BufferPtr = tokEnd;
}
