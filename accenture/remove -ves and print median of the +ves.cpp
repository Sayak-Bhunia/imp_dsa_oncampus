#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int n, vector<int> &a) {
    vector<int> b;
    for(auto it:a) {
        if(it>=0) b.push_back(it);
    }
    sort(b.begin(), b.end());
    if(b.size()%2 == 0) cout << b[(n/2)-1];
    else cout << b[b.size()/2] <<endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    helper(n, a);
}
