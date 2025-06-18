#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int n) {
    /* dp approach =>
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++) dp[i] = dp[i-1] + dp[i-2];
    */ 

    // space optimized approach =>
    int prev1 = 1, prev2 = 1, curr;
    for(int i=2;i<=n;i++) {
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;
}

int main() {
    int n;
    cin >> n;
    cout << helper(n) <<endl;
}
