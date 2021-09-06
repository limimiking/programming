/*************************************************************************
	> File Name: 150.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Thu Jun 24 20:36:39 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, m;
    int matrix[200][200];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &(matrix[i][j]));
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            j && printf(" ");
            printf("%d", matrix[n - j - 1][i]);
        }
        printf("\n");
    }
    return 0;
}
