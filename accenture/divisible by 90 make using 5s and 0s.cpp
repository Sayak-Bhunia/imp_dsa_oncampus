#include <bits/stdc++.h>
#define lint long long
using namespace std;

void helper(vector<int> &a, int n) {
    int c5 = 0, c0 = 0;
    for(auto it:a) {
        if(it == 5) c5++;
        else c0++;
    }
    if(c0 == 0) { // kono 0 nathkle 10 dea divisible hobe nah => 90 dea o divisible hobe nah
        cout << -1 <<endl;
        return;
    }
    c5 -= c5%9; // 9 er divisibility er nearest nos of 5 niye nilam
    if(c5 == 0) { // kono 5 na thakle sudhu 0 dea divisible hobe
        cout << 0 <<endl;
        return;
    }
    for(int i=0;i<c5;i++) cout << 5;
    for(int i=0;i<c0;i++) cout << 0;
    cout <<endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    helper(a, n);
}
