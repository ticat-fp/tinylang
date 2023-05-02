/*************************************************************************
	> File Name: CodeGen.h
	> Author: fanpeng
	> Mail: fanpeng@loongson.cn 
	> Created Time: 2023年04月23日 星期日 22时27分19秒
 ************************************************************************/

#ifndef CODEGEN_H
#define CODEGEN_H

#include "AST.h"

class CodeGen {
	public:
		void compile(AST *Tree);
};


#endif
