/*************************************************************************
	> File Name: 3.prime.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 26 17:11:23 2021
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 1000000

int is_prime(int n) {
    for (int i = 2, I = sqrt(n); i <= I; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    for (int i = 2; i <= MAX_N; i++) {
       if (is_prime(i)) printf("%d\n", i); 
    }
    return 0;
}
