/*************************************************************************
	> File Name: 170.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 10:14:56 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1000

int main() {
    int N;
    const char *sub = "Ban_smoking";
    const char *replace = "No_smoking";
    char **slogans;
    int len_sub = strlen(sub);
    int len_replace = strlen(replace);
    scanf("%d", &N);
    slogans = malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        slogans[i] = malloc(MAX_LENGTH * sizeof(char));
        memset(slogans[i], 0, MAX_LENGTH);
        char input[MAX_LENGTH];
        scanf("%s", input);
        for (int j = 0; j < strlen(input); j++) {
            if (!strncmp(input + j, sub, len_sub)) {
                strcat(slogans[i], replace);
                j += len_sub - 1;
            } else {
                strncat(slogans[i], input + j, 1);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%s\n", slogans[i]);
        free(slogans[i]);
    }
    free(slogans);
    return 0;
}
