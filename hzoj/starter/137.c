/*************************************************************************
	> File Name: 137.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jun 22 11:23:15 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, cnt = 0;
    char start = 'A';
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("%c", start + cnt);
            cnt++;
        }
        printf("\n");
    }
    return 0;
}
