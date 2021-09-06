/*************************************************************************
	> File Name: 446.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed Jul 14 11:33:53 2021
 ************************************************************************/

#include<stdio.h>

int min(int x, int y, int z, int w) {
    int min_xy = x > y ? y : x;
    int min_zw = z > w ? w : z;
    return min_xy > min_zw ? min_zw : min_xy;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            j == 0 || printf(" ");
            printf("%d", min(i + 1, j + 1, n - i, n - j));
        }
        printf("\n");
    }
    return 0;
}
