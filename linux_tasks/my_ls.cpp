/*************************************************************************
	> File Name: my_ls.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Sun 05 Dec 2021 06:15:28 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/types.h>

using namespace std;

int main() {
    DIR *dir;
    char str[100];
    string res[100];
    struct dirent *rent;
    dir =  opendir(".");
    int cnt = 0;
    while ((rent=readdir(dir))) {
        strcpy(str, rent->d_name);
        if (str[0] == '.')
            continue;
        if (!str)
            continue;
        res[cnt++] = str;
    }
    for (int i = 0; i < cnt; i++)
        cout << res[i] << " ";
    cout << endl;
    closedir(dir);
    return 0;
}

