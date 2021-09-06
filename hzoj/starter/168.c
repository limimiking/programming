/*************************************************************************
	> File Name: 168.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon 28 Jun 2021 09:35:51 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int N;
    char **name;
    scanf("%d", &N);
    name = malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        name[i] = malloc(105 * sizeof(char));
        scanf("%s", name[i]);
        if (name[i][0] >= 'a' && name[i][0] <= 'z') name[i][0] -= 32;
        for (int j = 1; j < strlen(name[i]); j++) {
            if (name[i][j] >= 'A' && name[i][j] <= 'Z') name[i][j] += 32;
        }
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strcmp(name[j], name[j + 1]) > 0) {
                char tmp[105];
                strcpy(tmp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], tmp);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%s\n", name[i]);
        free(name[i]);
    }
    free(name);
    return 0;

}
