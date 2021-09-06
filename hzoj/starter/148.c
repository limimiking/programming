/*************************************************************************
	> File Name: 148.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Thu Jun 24 20:24:10 2021
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    char str[50];
    int left, right;
    scanf("%s", str);
    left = 0;
    right = strlen(str) - 1;
    while (left < right) {
        str[left] ^= str[right];
        str[right] ^= str[left];
        str[left] ^= str[right];
        left++;
        right--;
    }
    printf("%s\n", str);
    return 0;
}
