/*************************************************************************
	> File Name: 188.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri 02 Jul 2021 09:46:17 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000005

int prime[MAX_N + 5] = {0};

void init_prime(int N) {
    for (int i = 2; i <= N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
            
        }

    }
    return;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    init_prime(n);
    for (int i = 1; i <= prime[0]; i++) {
        if (prime[i] > n) break;
        if (prime[i] >= m) printf("%d\n", prime[i]);
    }
    return 0;
}
