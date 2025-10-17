#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a;
    int x;
    while(cin >> x) a.push_back(x);
    unordered_map<int, int> dp;
    dp[0] = 0;
    for(auto it:a) {
        auto curr = dp;
        for(auto [diff, small]:curr) {
            dp[diff + it] = max(dp[diff + it], small);
            int nd = abs(diff - it);
            int ns = small + min(it, diff);
            dp[nd] = max(dp[nd], ns);
        }
    }
    cout << dp[0] <<endl;
}
