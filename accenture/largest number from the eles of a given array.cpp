#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(string &s) {
    string res;
    for(auto it:s) {
        if(it != ' ') res += it;
    }
    sort(res.begin(), res.end(), greater<int>());
    cout << res <<endl;
}

int main() {
    string s;
    getline(cin, s);
    helper(s);
}
