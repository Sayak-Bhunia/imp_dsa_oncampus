#include <bits/stdc++.h>
#define lint long long
using namespace std;

bool prime(int n) {
    if(n<=1) return false;
    for(int i=2;i<=sqrt(n);i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int helper(int n, vector<int> &a) {
    int sum = 0;
    for(int i=0;i<n;i++) {
        if(prime(i)) sum += a[i];
    }
    cout << sum <<endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    helper(n, a);
}
