// C++ program to count all palindromic substring of
// given string using bottom up DP

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countPS(string& s) {
    int n = s.length(), c = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0;i<n;i++) dp[i][i] = 1;
    for(int i=0;i<n-1;i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            c++;
        }
    }
    for(int i=2;i<n;i++) {
        for(int j=0;j<n-i;j++) {
            int k = j + i;
            if(s[j] == s[k] && dp[j+1][k-1]) {
                dp[j][k] = 1;
                c++;
            }
        }
    }
    return c;
}

int main() {
    string s = "abbaeae";
    cout << countPS(s) << endl;
    return 0;
}
