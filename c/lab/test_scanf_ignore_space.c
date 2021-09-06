/*************************************************************************
	> File Name: 2.test.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jun 22 13:04:56 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    char str[100] = {0};
    while (~scanf("%[^\n]s", str)) {
        getchar();
        printf(" has %d chars\n", printf("%s", str));
    }
    return 0;
}
