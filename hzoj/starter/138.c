/*************************************************************************
	> File Name: 138.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jun 22 11:28:54 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * (n - i); j++) {
            printf("A");
        }
        printf("\n");
    }
    return 0;
}
