#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(string &s) {
    string ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", res;
    int c = 0;
    for(auto it:s) {
        if(it == '1') c++;
        else {
            res += ch[c-1];
            c = 0;
        }
    }
    cout << res <<endl;
}

int main() {
    string s;
    cin >> s;
    helper(s);
}
