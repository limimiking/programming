/*************************************************************************
	> File Name: 146.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Thu Jun 24 20:05:32 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    char output[50] = {0};
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != '\n') {
        if (ch <= 'Z' && ch >= 'A' || ch <= 'z' && ch >= 'a') {
            if (ch == 'Z') ch = 'A';
            else if (ch == 'z') ch = 'a';
            else ch += 1;
        }
        output[cnt] = ch;
        cnt++;
    }
    printf("%s\n", output);

    return 0;
}
