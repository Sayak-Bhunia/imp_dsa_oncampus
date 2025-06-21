#include <bits/stdc++.h>
#define lint long long
using namespace std;

string helper(string &s) {
    string res;
    int c = 0;
    for(auto it:s) {
        if(it == '-') c++;
        else res += it;
    }
    while(c--) res = '-' + res;
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << helper(s) <<endl;
}
