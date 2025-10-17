#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    string s = string(a, 'a') + string(b, 'b') + string(c, 'c');
    set<string> res;
    sort(s.begin(), s.end());
    do {
        res.insert(s.substr(0, n));
    } while(next_permutation(s.begin(), s.end()));
    for(auto it:res) cout << it <<endl;
}
