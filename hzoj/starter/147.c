/*************************************************************************
	> File Name: 147.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Thu Jun 24 20:12:45 2021
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    char str[10000] = {0};
    scanf("%s", str);
    printf("%s\n", (str[strlen(str) - 1] - '0') & 1 ? "NO" : "YES");
    return 0;
}
