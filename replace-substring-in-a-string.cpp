// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// a = string to be replaced
// b = string to be replaced with

string helper(string &s, string &a, string &b) {
    string res;
    int n = s.length(), m = a.length();
    int i = 0;
    while(i<n) {
        if(i<=n-m && s.substr(i, m) == a) {
            res += b;
            i += m;
        }
        else res += s[i++];
    }
    return res;
}

int main() {
    string s,a,b;
    cin >> s >> a >> b;
    cout << helper(s, a, b) <<endl;
}
