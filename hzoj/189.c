/*************************************************************************
	> File Name: 189.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri Jun 18 14:50:28 2021
 ************************************************************************/
#include <stdio.h>

int n, k, num[1000005];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n ; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < k; i++) {
        int t, ans = 0, l = 1, r = n;;
        scanf("%d", &t);
        i == 0 || printf(" ");
        while (l <= r) {
            int mid = (r + l) / 2;
            if (num[mid] == t) {
                ans = mid;
                break;
            }
            if (num[mid] < t){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ans == 0) {
            printf("0");
        } else {
            printf("%d", ans);
        }
    }
    printf("\n");
    return 0;
}
