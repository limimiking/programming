/*************************************************************************
	> File Name: EP35.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat 03 Jul 2021 02:12:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};
void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;

}

//int get_digit(int n) {
//    int digit = 0;
//    do {
//        digit += 1;
//        n /= 10;
//    } while (n);
//    return digit;
//}

int get_digit(int n) {
    if (n == 0) return 1;
    return (int)(log10(n)) + 1;
}

int is_val(int n) {
    int digits = get_digit(n);
    int power = pow(10, digits - 1);
    for (int i = 0; i < digits - 1; i++) {
        n = (n % power) * 10 + n / power;
        if(is_prime[n]) return 0;
    }
    return 1;
}

int main() {
    init_prime();
    int cnt = 0;
    for (int i = 1; i <= prime[0]; i++) {
        cnt += is_val(prime[i]);
    }
    printf("%d\n", cnt);
    return 0;
}

