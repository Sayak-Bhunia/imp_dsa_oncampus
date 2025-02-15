#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool pal(int n) {
    int t = n, sum = 0;
    while(t != 0) {
        sum = sum*10 + t%10;
        t /= 10;
    }
    return sum == n;
}

int helper(vector<int> &a, int n) {
    int mx = -1;
    for(int i=0;i<n;i++) {
        if(pal(a[i])) mx = max(mx, a[i]);
    }
    return mx;
}

int main() {   
    int n = 8;
    vector<int> a = {121, 345, 678, 787, 232, 45654, 12321, 1};
    if(helper(a, n) == -1) cout << "no palindrom im the array" <<endl;
    else cout << helper(a, n) <<endl;
}
