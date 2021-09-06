/*************************************************************************
	> File Name: 204.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jul 13 10:58:09 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    int matrix[30][30];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &(matrix[i][j]));
        }
    }
    for (int i = 0; i < n; i++) printf("%d\n", matrix[i][i]);
    return 0;

}
