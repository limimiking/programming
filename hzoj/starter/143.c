/*************************************************************************
	> File Name: 143.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Thu Jun 24 19:43:29 2021
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


int main() {
    int a, b;
    int cnt = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        int tail = i % 100;
        int root = sqrt(tail);
        if(i % 6 == 0 && is_prime(i / 100) && root * root == tail) {
            cnt == 0 || printf(" ");
            printf("%d", i);
            cnt += 1;
        }
    }
    printf("\n%d\n", cnt);
    return 0;
}
