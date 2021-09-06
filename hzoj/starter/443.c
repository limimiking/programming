/*************************************************************************
	> File Name: 443.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jul 13 10:41:27 2021
 ************************************************************************/

#include<stdio.h>

int cut_tree[10000] = {0};

int main() {
    int L, M;
    int cut = 0;
    scanf("%d%d", &L, &M);
    for (int i = 0; i < M; i++) {
        int start, end;
        scanf("%d%d", &start, &end);
        for (int j = start; j <= end; j++) cut_tree[j] = 1;
    }
    for (int i = 0; i <= L; i++) cut += cut_tree[i]; 
    printf("%d\n", L + 1 - cut);
    return 0;
}
