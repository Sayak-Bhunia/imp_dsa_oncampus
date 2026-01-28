#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define lint long long int

int main() {
    int n;
    cin >> n;
    vector<int> pr(n+1), rb(n+1);
    vector<vector<int>> ch(n+1);
    for(int i=1;i<=n;i++) {
        cin >> pr[i] >> rb[i];
        if(pr[i] != -1) ch[pr[i]].push_back(i);
    }
    vector<bool> rm(n+1, false);
    vector<int> res;
    while(1) {
        int c = -1;
        for(int i=1;i<=n;i++) {
            if(rm[i]) continue;
            if(pr[i] == -1) continue;
            if(rb[i] == 0) continue;
            bool f = false;
            for(int it:ch[i]) {
                if(!rm[it] && rb[it] == 0) {
                    f = true;
                    break;
                }
            }
            if(!f) {
                c = i;
                break;
            }
        }
        if(c == -1) break;
        rm[c] = true;
        res.push_back(c);
        int p = pr[c];
        for(int it:ch[c]) {
            pr[it] = p;
            if(!rm[it]) {
                if(p != -1) ch[p].push_back(it);
            }
        }
        ch[c].clear();
    }
    if(res.empty()) cout << -1 <<endl;
    else {
        for(auto it:res) cout << it << " ";
        cout <<endl;
    }
}
