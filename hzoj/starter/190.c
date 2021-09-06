/*************************************************************************
	> File Name: 190.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri 02 Jul 2021 10:07:44 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 8000000

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
    int n;
    int cnt = 0;
    scanf("%d", &n);
    init_prime(n);
    int left = 1, right = prime[0];
    while (left <= right) {
        if (prime[left] + prime[right] == n) {
            cnt++;
            left++;
            right--;
        }
        if (prime[left] + prime[right] > n) right--;
        if (prime[left] + prime[right] < n) {
            left++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}
