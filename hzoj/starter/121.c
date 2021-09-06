/*************************************************************************
	> File Name: 121.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 14:39:08 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    char a, b;
    char *ans;
    scanf("%c %c", &a, &b);
    if (a == b) {
        ans = "TIE";
    } else if (a == 'O') {
        if (b == 'Y') ans = "MING";
        else ans = "LI";
    } else if (a == 'Y') {
        if (b == 'H') ans = "MING";
        else ans = "LI";
    } else {
        if (b == 'O') ans = "MING";
        else ans = "LI";
    }
    printf("%s\n", ans);
    return 0;
}
