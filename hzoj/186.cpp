/*************************************************************************
	> File Name: 186.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sat Jun 19 10:39:30 2021
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
    int n, pos = 0, count = 0;
    int a[100005];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    while (pos < n) {
        pos += a[pos];
        count += 1;
    }
    printf("%d\n", count);
    
    return 0;
}
