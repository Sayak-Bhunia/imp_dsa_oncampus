#include <bits/stdc++.h>
#define lint long long
using namespace std;

bool helper(string &s) {
    stringstream ss(s);
    string w, res;
    while(ss>>w) {
        if(w.length()>res.length()) res = w;
    }
    cout << res <<endl;
}

int main() {
    string s;
    getline(cin, s);
    helper(s);
}
