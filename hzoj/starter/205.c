/*************************************************************************
	> File Name: 205.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jul 13 11:02:45 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, m;
    int matrix[30][30] = {0};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &(matrix[i][j]));
        }
    }
    for (int i = 0; i < n; i++) {
        double mean = 0;
        for (int j = 0; j < m; j++) mean += matrix[i][j];
        mean /= m;
        printf("%.6lf\n", mean);
    }
    return 0;
}

