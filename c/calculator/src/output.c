/*************************************************************************
	> File Name: src/output.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri Jul  9 11:55:04 2021
 ************************************************************************/

#include<stdio.h>
#include"output.h"
#include"input.h"
#include"calc.h"

int output(char **exprs, int cnt_lines) {
    if (cnt_lines < 0) return -1;
    if (cnt_lines == 1) {
        double ans = calc(exprs[0]);
        printf("%s = %g\n", exprs[0], ans);
        return 0;
    }
    char file_path[FILE_PATH_MAX_LENGTH];
    strcpy(file_path, exprs[cnt_lines - 1]);
    strcat(file_path, ".out");
    FILE *fp = fopen(file_path, "w");
    for (int i = 0; i < cnt_lines - 1; i++) {
        double ans = calc(exprs[i]);
        fprintf(fp, "%s = %g\n", exprs[i], ans);
    }
    return 0;
}
