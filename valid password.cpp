#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(string &s) {
    if(isdigit(s[0])) return 0;
    if(s.length()<4) return 0;
    bool f1 = false, f2 = false, f3 = false;
    for(auto it:s) {
        if(isdigit(it)) f1 = true;
        else if(isupper(it)) f2 = true;
        else if(it == ' ' || it == '/') f3 = true;;
    }
    if(!f1 || !f2 || f3) return 0;
    return 1;
}

int main() {
    string s;
    getline(cin, s);
    cout << helper(s) <<endl;
}
