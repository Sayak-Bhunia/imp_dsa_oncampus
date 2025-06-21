#include <bits/stdc++.h>
#define lint long long
using namespace std;

string helper(string &s, char a, char b) {
    string res;
    for(auto it:s) {
        if(it == a) res += b;
        else if(it == b) res += a;
        else res += it;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    char a,b;
    cin >> a >> b;
    cout << helper(s, a, b) <<endl;
}
