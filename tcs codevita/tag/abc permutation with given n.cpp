#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    // string line;
    // getline(cin, line); // read the entire line as a string

    // istringstream iss(line);
    // int a, b, c, n;
    // iss >> a >> b >> c >> n;
    // int a,b,c,n;
    cin >> a >> b >> c >> n;
    string s = string(a, 'a') + string(b, 'b') + string(c, 'c');
    set<string> res;
    sort(s.begin(), s.end());
    do {
        res.insert(s.substr(0, n));
    } while(next_permutation(s.begin(), s.end()));
    for(auto it:res) cout << it <<endl;
}
