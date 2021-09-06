/*************************************************************************
	> File Name: 464.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri Jun 18 15:21:43 2021
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int x, y;
    int sum = 0;
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) {
            sum += 1;
        }
    }
    cout << sum << endl;
    return 0;
}
