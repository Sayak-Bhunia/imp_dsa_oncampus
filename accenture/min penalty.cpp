#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(vector<int> &a, int n) {
    sort(a.begin(), a.end());
    int sum = 0;
    for(int i=0;i<n-1;i++) sum += a[i+1] - a[i];
    cout << sum <<endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    helper(a, n);
}
