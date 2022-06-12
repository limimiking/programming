/*************************************************************************
	> File Name: next_permutation.cpp
	> Author: Bruce_Lin
	> Mail: xiaotian.lin@hit.edu.cn
	> Created Time: Wed 08 Sep 2021 05:41:30 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>


template<class BidirIt>
bool next_perm(BidirIt first, BidirIt last)
{
    if (first == last) return false;
    BidirIt i = last;
    if (first == --i) return false;
 
    while (true) {
        BidirIt i1, i2;
 
        i1 = i;
        if (*--i < *i1) {
            i2 = last;
            while (!(*i < *--i2))
                ;
            std::iter_swap(i, i2);
            std::reverse(i1, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    // std::string s = "ab";
    do {
        for (int& c : arr) std::cout << c << ' ';
        std::cout << std::endl;
        // std::cout << s << '\n';
    // } while(next_perm(s.begin(), s.end()));
    } while (next_perm(arr, arr + 4));
    return 0;
}
