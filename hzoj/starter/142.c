/*************************************************************************
	> File Name: 142.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Thu Jun 24 19:20:24 2021
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int is_prime(int n) {
    if (!(n > 1)) return 0;
    for (int i = 2; i <= sqrt(n) ; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int is_palindrome(int n) {
    if (n < 0) return 0;
    int tmp = n;
    int reverse = 0;
    while(tmp) {
        reverse = reverse * 10 + tmp % 10;
        tmp /= 10;
    }
    return reverse == n;
}

int main() {
    int a, b;
    int first_found = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (is_prime(i) && is_palindrome(i)) {
            first_found && printf(" ");
            first_found = 1;
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}
