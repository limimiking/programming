/*************************************************************************
	> File Name: 189.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Fri Jun 18 14:50:28 2021
 ************************************************************************/

#include<iostream>
using namespace std;
int n, k, num[1000005];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n ; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < k; i++) {
        int t, ans = 0, l = 1, r = n;;
        cin >> t;
        i == 0 || cout << " ";
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
            cout << 0;
        } else {
            cout << ans;
        }
    }
    cout << endl;
    return 0;
}
