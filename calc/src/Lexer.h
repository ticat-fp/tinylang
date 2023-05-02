/*************************************************************************
	> File Name: Lexer.h
	> Author: fanpeng
	> Mail: fanpeng@loongson.cn 
	> Created Time: 2023年04月17日 星期一 22时57分08秒
 ************************************************************************/

#ifndef LEXER_H
#define LEXER_H

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/MemoryBuffer.h"

class Lexer;

class Token {
	friend class Lexer;

public:
	enum TokenKind: unsigned short {
		eoi,		// end of input
		unknown,
		ident,
		number,
		comma,
		colon,
		plus,
		minus,
		star,
		slash,
		l_paren,
		r_paren,
		KW_with,
	};

private:
	TokenKind Kind;
	llvm::StringRef Text;		// start of token stream text

public:
	TokenKind getKind() const { return Kind; }
	llvm::StringRef getText() { return Text; }

	bool is(TokenKind kind) const { return kind == Kind; }
	bool isOneOf(TokenKind kind1, TokenKind kind2) const { 
		return is(kind1) || is(kind2);
	}

	template <typename... Ts>
	bool isOneOf(TokenKind kind1, TokenKind kind2, Ts...Ks) const {
		return is(kind1) || isOneOf(kind2, Ks...);
	}
};

class Lexer {
	const char *BufferStart;
	const char *BufferPtr;

public:
	Lexer(const llvm::StringRef &Buffer) {
		BufferStart = Buffer.begin();
		BufferPtr = BufferStart;
	}

	void next(Token &token);

private:
	void formToken(Token &result, const char *TokEnd, Token::TokenKind Kind);
};

#endif
