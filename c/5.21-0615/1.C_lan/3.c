/*************************************************************************
	> File Name: 3.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Tue Jun 22 13:34:04 2021
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    char str[100] = {0};
    int arr[4] = {0};
//    scanf("%d", &n);
//    printf("%d\n",n);
    sprintf(str, "%d.%d.%d.%d", 192, 168, 0, 1);
    sscanf(str, "%d.%d.%d.%d", &arr[0],&arr[1], &arr[2], &arr[3]);
    printf("%s", str);
    for (int i = 0; i < 4; i++) {
        printf("%d\n", arr[i]);
    }
    FILE *fp = fopen("./output", "a+");
    fprintf(fp, "str = %s\n", str);
    fclose(fp);
    char ans[10000] = {0}, tmp;
    int offset = 0;
    FILE *fin = fopen("./output", "r");
    while (~fscanf(fin, "%c", &tmp)) {
        offset += sprintf(ans + offset, "%c", tmp);
    }
    fclose(fin);
    printf("%s", ans);
    return 0;
}
