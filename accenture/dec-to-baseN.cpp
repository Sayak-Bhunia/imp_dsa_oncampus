#include <bits/stdc++.h>
#define lint long long
using namespace std;

string helper(int n, int m) {
    if(m == 0) return "0";
    string ch = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", res;
    while(m != 0) {
        res = ch[m%n] + res;
        m /= n;
    }
    return res;
}

int main() {
    int n,m;
    cin >> n >> m;
    cout << helper(n, m) <<endl;
}
