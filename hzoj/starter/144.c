/*************************************************************************
	> File Name: 144.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Thu Jun 24 19:57:18 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int cnt = 0;
    char ch;
    while((ch = getchar()) != '\n') {
        if (ch == 'A') cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
