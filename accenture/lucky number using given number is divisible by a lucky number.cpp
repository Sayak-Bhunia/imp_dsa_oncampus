#include <bits/stdc++.h>
#define lint long long
using namespace std;

void helper(lint i, lint n, vector<lint> &a) {
    if(i>n) return;
    if(i>0) a.push_back(i);
    helper(i*10 + 4, n, a);
    helper(i*10 + 7, n, a);
}

int main() {
    lint n;
    cin >> n;
    vector<lint> a;
    helper(0, n, a);
    bool f = false;
    for(auto it:a) {
        if(n%it == 0) {
            f = true;
            break;
        }
    }
    if(f) cout << "almost lucky" <<endl;
    else cout << "not almost lucky" <<endl;
}
