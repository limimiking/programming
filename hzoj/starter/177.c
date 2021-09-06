/*************************************************************************
	> File Name: 177.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed 30 Jun 2021 04:12:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    char str[30];
    char tail[30] = {0};
    scanf("%s", str);
    int l = strlen(str);
    for (int i = 0; i < l; i++) {
        printf("%s\n", str);
        strcpy(tail, str + l - 2);
        strncat(tail, str, l - 2);
        strcpy(str, tail);
    }
    return 0;
}
