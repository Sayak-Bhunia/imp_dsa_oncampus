#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int n, int k, vector<int> &a) {
    int sum = 0;
    for(int i=0;i<k;i++) sum += a[i];
    int mn = sum;
    vector<int> b(a.begin(), a.end() + k);
    for(int i=k;i<n;i++) {
        sum += a[i] - a[i-k]; // left element minus kore right er new element plus korchi mane window soracchi
        if(sum<mn) {
            mn = sum;
            b.clear(); // new elements gulo k add korchi jader minimum sum
            for(int j=i-k+1;j<=i;j++) b.push_back(a[j]);
        }
    }
    for(auto it:b) cout << it << " ";
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    helper(n, k, a);
}
