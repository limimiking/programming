/*************************************************************************
	> File Name: 448.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jul 13 10:26:53 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, num, nums[100];
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &num);
    for (int i = 0; i < n; i++) {
        if (num == nums[i]) {
            cnt = i + 1;
            break;
        }
    }
    printf("%d\n", cnt);

}
