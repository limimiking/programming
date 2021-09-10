/*************************************************************************
	> File Name: 263.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed 08 Sep 2021 04:32:08 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

#define MAX_N 20
int arr[MAX_N + 5];

int is_valid(int *arr, int n) {
    stack<int> s;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        while (tmp < arr[i]) s.push(++tmp);
        if (s.top() != arr[i]) return false;
        s.pop();
    }
    return true;

}

int main() {
    int n, cnt = 20;
    cin >> n;
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    do {
        if (is_valid(arr, n)) {
            for (int i = 0; i < n; i++) {
                cout << arr[i];
            }
        cout << endl;
        cnt--;
        }
    } while (next_permutation(arr, arr + n) && cnt);

    return 0;
}
