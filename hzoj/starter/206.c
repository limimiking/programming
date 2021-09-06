/*************************************************************************
	> File Name: 206.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed Jul 14 11:30:25 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, m;
    int matrix[30][30];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][j];
        }
        printf("%d\n", sum);
    } 

    return 0;
}
