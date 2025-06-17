#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(string &a, string &b) {
    int c = 0;
    for(auto it:b) {
        if(c<a.length() && it == a[c]) c++;
    }
    cout << ++c <<endl;
}

int main() {
    string a,b;
    cin >> a >> b;
    helper(a, b);
}
