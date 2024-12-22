#include <bits/stdc++.h>
#define lint long long 
using namespace std;

void decton(int b, int n) {
    if(n == 0) return;
    const char ch[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    decton(b, n/b);
    cout << ch[n%b];
}

int main() {   
    int b,n;
    cin >> b >> n;
    if(n == 0) cout << "0";
    decton(b, n);
}
