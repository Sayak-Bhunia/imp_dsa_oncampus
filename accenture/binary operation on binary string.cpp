#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(string &s) {
    if(!s.length()) return -1;
    int res = s[0] - '0';
    for(int i=1;i<s.length();i+=2) {
        if(s[i] == 'A') res &= s[i+1] - '0';
        else if(s[i] == 'B') res |= s[i+1] - '0';
        else if(s[i] == 'C') res ^= s[i+1] - '0';
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << helper(s) <<endl;
}

