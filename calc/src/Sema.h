/*************************************************************************
	> File Name: Sema.h
	> Author: fanpeng
	> Mail: fanpeng@loongson.cn 
	> Created Time: 2023年04月21日 星期五 20时30分45秒
 ************************************************************************/

#ifndef SEMA_H
#define SEMA_H

#include "AST.h"
#include "Lexer.h"

class Sema {
public:
	bool semantic(AST *Tree);
};

#endif
