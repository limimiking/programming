/*************************************************************************
	> File Name: input.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jun 22 14:17:02 2021
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "input.h"


int input(char ***exprs) {
    int input_type;
    printf("choose input type, 0 for stdio, 1 for file\n");
    scanf("%d", &input_type);
    if (input_type == 0) {
        *exprs = (char **)malloc(sizeof(char*));
        (*exprs)[0] = (char *)malloc(sizeof(char) * EXPR_MAX_LENGTH);
        getchar();
        scanf("%[^\n]s", (*exprs)[0]);
        return 1;
    }
    if (input_type == 1) {
        char file_path[FILE_PATH_MAX_LENGTH];
        int cnt_lines = 0, chr;
        printf("Please input file path:\n");
        scanf("%s", file_path);
        FILE *fp = fopen(file_path, "r");
        if (fp == NULL) {
            printf("no such file\n");
            return -2;
        }
        while ((chr = fgetc(fp)) != EOF) {
            if (chr == '\n') cnt_lines++;
        }
        if (!cnt_lines) {
            printf("empty file\n");
            return -3;
        }
        rewind(fp);
        *exprs = (char **)malloc(sizeof(char*) * (cnt_lines + 1));
        for (int i = 0; i < cnt_lines; i++) {
            (*exprs)[i] = (char *)malloc(sizeof(char) * EXPR_MAX_LENGTH);
            i == 0 || fgetc(fp);
            fscanf(fp, "%[^\n]s", (*exprs)[i]);
            #ifdef DEBUG
            printf("%s\n", (*exprs)[i]);
            #endif
        }
        (*exprs)[cnt_lines] = (char *)malloc(strlen(file_path) * sizeof(char));
        strcpy((*exprs)[cnt_lines], file_path);
        fclose(fp);
        return cnt_lines + 1;
    }
    printf("invalid input\n");
    return -1;
}

