#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void helper(string &s, int n) {
    if(n<0) return;
    cout << s[n];
    helper(s, n-1);
}

int main() {
    string s;
    getline(cin, s);
    helper(s, s.length() - 1);
}
