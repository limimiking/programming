/*************************************************************************
	> File Name: 114.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jul 12 15:51:56 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    char name;
    char *ans;
    scanf("%c", &name);
    switch (name) {
        case 'h':
            ans = "He";
            break;
        case 'l':
            ans = "Li";
            break;
        case 'c':
            ans = "Cao";
            break;
        case 'd':
            ans = "Duan";
            break;
        case 'w':
            ans = "Wang";
            break;
        default:
            ans = "Not Here";
    }
    printf("%s\n", ans);
    return 0;
}
