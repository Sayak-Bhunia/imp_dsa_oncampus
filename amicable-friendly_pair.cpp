#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int helper(int n) {
    int m = 0;
    for(int i=1;i<=n/2;i++) {
        if(n%i == 0) m += i;
    }
    return m;
}

int main() {
    int a,b;
    cin >> a >> b;
    int n;
    cin >> n;
    if(helper(a) == b && helper(b) == a) cout << "YES" <<endl;
    else cout << "NO" <<endl;
}
