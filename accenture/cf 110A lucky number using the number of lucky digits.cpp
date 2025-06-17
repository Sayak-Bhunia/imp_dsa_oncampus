#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int n) {
    bool f = false;
    if(n == 0) f = true;
    while(n != 0) {
        if(n%10 != 7 && n%10 != 4) f = true;
        n /= 10;
    }
    if(!f) cout << "alsmost lucky" <<endl;
    else cout << "not almost lucky" <<endl;
}

int main() {
    string s;
    cin >> s;
    int c = 0;
    for(auto it:s) {
        if(it == '4' || it == '7') c++;
    }
    helper(c);
}
