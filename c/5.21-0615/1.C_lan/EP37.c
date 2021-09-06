/*************************************************************************
	> File Name: EP37.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sun Jul 11 11:05:26 2021
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};

void init_prime() {
    is_prime[0] = 1;
    is_prime[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > MAX_N) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int get_digit(int n) {
    if (n == 0) return 1;
    return (int)log10(n) + 1;
}

int is_val(int n) {
    int digits = get_digit(n);
    int power;
    int x = n;
    while (x) {
        if (is_prime[x]) return 0;
        x /= 10;
    }
    x = n;
    while (digits >= 1) {
        power = pow(10, digits - 1);
        if (is_prime[x]) return 0;
        x = x % power;
        digits -= 1;
    }
    return 1;
}

int main() {
    long long int sum = 0;
    init_prime();
    printf("%d\n", is_prime[131]);
    printf("%d\n", is_val(3797));
    for (int i = 5, cnt = 0; cnt < 11; i++) {
        if (is_val(prime[i])) {
            printf("find %d\n", prime[i]);
            sum += prime[i];
            cnt++;
        }
    }
    printf("%lld\n", sum);
}
