/*************************************************************************
	> File Name: 173.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed Jun 30 10:05:13 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int alphabet = 0, number = 0, space = 0, other = 0;
    char ch;
    while((ch = getchar()) != '\n') {
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') alphabet++;
        else if (ch >= '0' && ch <= '9') number++;
        else if (ch == ' ') space++;
        else other++;
    }
    printf("%d %d %d %d\n", alphabet, number, space, other);
    return 0;
}
