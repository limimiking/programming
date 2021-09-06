/*************************************************************************
	> File Name: 2.my_printf.c
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Thu Jun 24 20:58:11 2021
 ************************************************************************/

#include<stdio.h>
#include<stdarg.h>
#include<inttypes.h>

int reverse_num(int x, int *tmp) {
    int digit = 0;
    do {
        *tmp = *tmp * 10 + x % 10;
        x /= 10;
        digit += 1;
    } while(x);
    return digit;
}

int output_num(int x, int digit) {
    int cnt = 0;
    while (digit--) {
        putchar(x % 10 + '0'), cnt++;
        x /= 10;
    }
    return cnt;
} 
int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    #define PUTC(a) putchar(a), ++cnt
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case '%': PUTC(frm[i]); break;
                    case 'd': {
                        int x = va_arg(arg, int);
                        unsigned int x_unsigned = 0;
                        if (x < 0) PUTC('-'), x_unsigned = -x;
                        else x_unsigned = x;
                        // int x_h = x_unsigned / 100000, x_l = x_unsigned % 100000;
                        int x_h = x_unsigned / 10, x_l = x_unsigned % 10;
                        int tmp_h = 0, tmp_l = 0;
                        int digit_h = reverse_num(x_h, &tmp_h);
                        int digit_l = reverse_num(x_l, &tmp_l);
                        //int digit_zero_fill;
                        //if (x_h) digit_zero_fill = 5 - digit_l;
                        if (!x_h) digit_h = 0;
                        cnt += output_num(tmp_h, digit_h); //problem output "100123"
                        //cnt += output_num(0, digit_zero_fill);
                        cnt += output_num(tmp_l, digit_l);
                    } break;
                    case 's': {
                        const char *str = va_arg(arg, const char*);
                        for (int i = 0; str[i]; i++) {
                            PUTC(str[i]);
                        }
                    } break;
                }
            } break;
            default: PUTC(frm[i]); break;
        }
    }
    #undef PUTC
    va_end(arg);
    return cnt;
}
int main() {
    char str[100] = {0};
    str[0] = 'a';
    str[1] = 'b';
    printf("hello lxt %d\n", 1234);
    my_printf("hello lxt %d\n", 1234);
    my_printf("hello lxt %d\n", 0);
    my_printf("hello lxt %d %d\n", -123, 1000);
    my_printf("%d %d\n", INT32_MAX, 100123);
    my_printf("%d %d\n", INT32_MIN, 100123);
    my_printf("%s %d\n", str, 100123);
    int n;
    while(~scanf("%d", &n)) {
        my_printf(" has %d digits\n", my_printf("%d", n));
    }
    return 0;
}
