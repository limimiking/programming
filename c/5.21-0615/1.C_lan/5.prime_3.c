/*************************************************************************
	> File Name: 5.prime_3.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jun 29 17:26:45 2021
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000


int prime[MAX_N + 5] = {0};
int ans[MAX_N + 5] = {0};
int cnt = 0;

void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        cnt += 1;
        ans[cnt] = i;
        for (int j = i, I = MAX_N / i; j <= I; j++) {
            prime[i * j] = 1;
        }
    }
}
int main() {
    init_prime();
    for (int i = 1; i <= cnt; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
