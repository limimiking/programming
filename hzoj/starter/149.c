/*************************************************************************
	> File Name: 149.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Thu Jun 24 20:33:41 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int length = 0;
    char ch;
    while((ch = getchar()) != '\n') {
        if (ch == ' ') length = 0;
        else length++;
    }
    printf("%d\n", length);
    return 0;
}
