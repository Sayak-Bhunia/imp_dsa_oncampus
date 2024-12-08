#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 0;
    for(int i=1;i<=n/2;i++) {
        if(n%i == 0) m += i;
    }
    if(m == n) cout << "YES" <<endl;
    else cout << "NO" <<endl;
}
