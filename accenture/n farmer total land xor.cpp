#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int n) {
    vector<int> a(n);
    a[1] = 1;
    for(int i=2;i<n;i++) a.push_back(a[i-1]^i);
    int sum = 0;
    for(auto it:a) sum +=  it;
    cout << sum <<endl;
}

int main() {
    int n;
    cin >> n;
    helper(n);
}
