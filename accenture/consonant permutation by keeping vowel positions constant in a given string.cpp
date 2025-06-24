#include <bits/stdc++.h>
#define lint long long
using namespace std;

lint fact(lint n) {
    lint c = 1;
    for(int i=1;i<=n;i++) c *= i;
    return c;
}

int helper(string &s) {
    int c = 0;
    unordered_map<char, int> mp;
    for(auto it:s) {
        if(it != 'A' && it != 'E' && it != 'I' && it != 'O' && it != 'U') {
            c++;
            mp[it]++;
        }
    }
    lint res = fact(c);
    for(auto it:mp) res /= fact(it.second);
    return int(res);
}

int main() {
    string s;
    cin >> s;
    cout << helper(s) <<endl;
}
