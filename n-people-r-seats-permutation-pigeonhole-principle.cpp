#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define lint long long int

lint f(int n) {
    lint p = 1;
    for(int i=1;i<=n;i++) p *= i;
    return p;
}

lint helper(int n, int r) {
    if(r>n) return 0;
    return f(n)/f(n-r);
}

int main() {
    int n,r;
    cin >> n >> r;
    cout << helper(n, r) <<endl;
}
