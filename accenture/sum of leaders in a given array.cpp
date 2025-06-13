#include <bits/stdc++.h>
#define lint long long
using namespace std;

bool helper(vector<int> &a, int n) {
    int res = 0;
    for(int i=n-2;i>=0;i--) {
        if(a[i]>a[n-1]) {
            res += a[i];
            a[n-1] = a[i];
        }
    }
    cout << res <<endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    helper(a, n);
}
