/*************************************************************************
	> File Name: 172.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jun 29 11:05:20 2021
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    char names[10][25] = {0};
    for (int i = 0; i < 10; i++) scanf("%s", names[i]);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                char tmp[25] = {0};
                strcpy(tmp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tmp);
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%s\n", names[i]);
    }
    return 0;
}
