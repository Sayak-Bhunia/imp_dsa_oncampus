#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(string &s, char x) {
    unordered_map<char, int> mp;
    for(auto it:s) mp[it]++;
    char y;
    int mx = -1;
    for(auto it:mp) {
        if(it.second>mx) {
            mx = it.second;
            y = it.first;
        }
    }
    for(auto &it:s) it = (it == y)? x:it;
    cout << s <<endl;
}

int main() {
    string s;
    cin >> s;
    char x;
    cin >> x;
    helper(s, x);
}
