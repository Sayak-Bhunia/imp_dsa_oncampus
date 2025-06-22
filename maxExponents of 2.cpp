#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper1(int n) {
    int c = 0;
    while(n%2 == 0) {
        c++;
        n /= 2;
    }
    return c;
}

int helper(int a, int b) {
    int mx = -1, res = a;
    for(int i=a;i<=b;i++) {
        int c = helper1(i);
        if(c>mx) {
            mx = c;
            res = i;
        }
        else if(mx == c && i<res) res = i;
    }
    return res;
}

int main() {
    int a,b;
    cin >> a >> b;
    cout << helper(a, b) <<endl;
}
