# 使用手册

## 1.工程说明

​	src存放了所有源码，目前calculator.c为主程序源码，input.c为input模块，elem_arith为四则运算模块，include文件夹中存放了各个模块对应的头文件，exprs.txt为表达式文件，Makefile为编译过程描述文件，可通过make命令直接编译生成可执行文件calculator

## 2. 函数

### (1)input

​	函数声明:	`int input(char ***exprs)`

​	功能:			从标准输入或文件中读取运算表达式

​	输入参数:	一个二级字符指针的地址`char ***exprs`，用于存放表达式

​	输出参数:	整型数值`n`，表达式个数或错误码

​	函数使用说明:

​		（1）在主程序中引用input.h头文件

​		（2）定义一个二级字符指针`char **exprs`和一个整型数值`n`以接收函数返回值

​		（3）`n = input(&exprs);`

​		程序运行中会有文字提示，根据提示进行相应输入即可。

​		注意调用结束后，如果不再使用表达式，需要对指针进行释放

​	返回值说明:

​		返回值为正整数，则为获取的表达式个数

​		返回值为-1，则说明用户输入有误

​		返回值为-2，则说明文件不存在

​		返回值为-3，则说明文件为空

​	编程实例:

```c
#include<stdio.h>
#include<stdlib.h>
#include"input.h"

int main() {
    char **exprs;
    int n;
    n = input(&exprs);
    if (n < 0) return n;
    for (int i = 0; i < n; i++) {
        printf("expression %d is: %s\n", i + 1, exprs[i]);
    }

    for (int i = 0; i < n; i++) free(exprs[i]);
    free(exprs);
    return 0;
}
```
### (2)add, sub, multiply, divide

​	函数声明add:	`double add(double, double)`
​	函数声明sub:	`double sub(double, double)`
​	函数声明multiply:	`double multiply(double, double)`
​	函数声明sub:	`double add(double, double)`

​	功能:			两数相加减乘除，异常情况进行提示

​	输入参数:	两个double类型数，表示两个运算数

​	输出参数:	doubled类型，运算结果

​	函数使用说明:

​		（1）在主程序中引用elem_arith.h头文件

​		（2）定义待运算的变量，将其赋值或从表达式中取值，或使用立即数

### (3)my_pow, my_sqrt

​	函数声明:	`double my_pow(double, double)`, `double my_sqrt(double)`

​	功能:			my_pow: 计算幂	my_sqrt: 计算平方根

​	输入参数:	my_pow: 两个`double`，分别表示底与指数

​						my_sqrt: `double`，待开方数

​	输出参数:	双精度浮点数`double`，计算结果

​	函数使用说明:

​		（1）在主程序中引用my_pow.h和my_sqrt.h头文件

​		（2）定义相应待计算变量

​		（3）调用函数计算结果

​	返回值说明:

​		根据输入参数的不同，会返回某些特殊值

​		返回值为inf，则说明计算出无穷大

​		返回值为nan，说明无法计算

### (4)calc

​	函数声明:	`double calc(char *)`

​	功能:			根据输入的表达式字符串计算表达式的值，具有一定判断非法表达式的能力

​	输入参数:	`char *`，表达式字符串

​	输出参数:	双精度浮点数`double`，计算结果

​	函数使用说明:

​		（1）在主程序中引用calc.h头文件

​		（2）定义表达式字符串

​		（3）调用函数计算结果

​	返回值说明:

​		目前不支持单目减号，负值只能通过四则运算获得，单目减号会被认为是非法表达式

​		根据表达式的不同，会返回某些特殊值

​		返回值为inf，则说明计算出无穷大

​		返回值为nan，说明无法计算

### (5)output

​	函数声明:	`int output(char **, int)`

​	功能:			将输入的表达式值输出到标准输出或文件中

​	输入参数:	`char **`，存储多个表达式

​						`int`，表达式行数

​	输出参数:	`int`，运行成功于否的标志

​	函数使用说明:

​		（1）在主程序中引用output.h头文件

​		（2）利用input函数从标准输入输出或文件中获取一个或多个表达式

​		（3）调用output函数

​	返回值说明:

​		返回值为-1，输入的表达式有问题

​		返回值为0，调用成功
