#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(vector<int> &a, int n) {
    int mx = INT_MIN, pos = -1;
    for(int i=0;i<n;i++) {
        if(a[i]>mx) {
            mx = a[i];
            pos = i;
        }
    }
    cout << mx <<endl;
    cout << pos <<endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    helper(a, n);
}
