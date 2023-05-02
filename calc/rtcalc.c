/*************************************************************************
	> File Name: rtcalc.c
	> Author: fanpeng
	> Mail: fanpeng@loongson.cn 
	> Created Time: 2023年04月28日 星期五 22时03分28秒
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>

void calc_write(int v) {
	printf("The result is: %d\n", v);
}

int calc_read(char *s) {
	char buf[64];
	int val;
	printf("Enter a value for %s:", s);
	fgets(buf, sizeof(buf), stdin);

	if (EOF == sscanf(buf, "%d", &val)) {
		printf("Value %s is invalid!\n", buf);
		exit(1);
	}

	return val;
}
