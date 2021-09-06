/*************************************************************************
	> File Name: 133.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Mon Jun 21 20:33:07 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            j == 0 || printf("\t");
            printf("%d*%d=%d", i + 1, i + j + 1, (i + 1) * (i + j + 1));
        }
        printf("\n");
    }
    return 0;
}
