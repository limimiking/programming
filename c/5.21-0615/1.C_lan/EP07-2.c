/*************************************************************************
	> File Name: EP07-2.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed 30 Jun 2021 05:26:34 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 100000000

int prime[MAX_N + 5] = {0};

void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        //enumerate M
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            int N = prime[j] * i;
            if (N > MAX_N) break;
            prime[N] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}
int main() {
    init_prime();
    for (int i = 1; i <= prime[0]; i++) {
        printf("%d\n", prime[i]);
    }
    return 0;
}
