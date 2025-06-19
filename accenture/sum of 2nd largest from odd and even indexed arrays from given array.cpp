#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int v, int w) {
    
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b, c;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        if(i%2 == 0) b.push_back(x);
        else c.push_back(x);
    }
    int p = INT_MIN, q = INT_MIN, sum = 0;
    for(auto it:b) {
        if(it>p) {
            q = p;
            p = it;
        }
        else if(it>q && it != p) q = it;
    } 
    sum += q;
    p = INT_MIN, q = INT_MIN;
    for(auto it:c) {
        if(it>p) {
            q = p;
            p = it;
        }
        else if(it>q && it != p) q = it;
    } 
    sum += q;
    cout << sum <<endl;
}
