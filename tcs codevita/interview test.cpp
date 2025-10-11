#include <bits/stdc++.h>
using namespace std;

vector<int> tmp = {
    0b1111110, 
    0b0110000, 
    0b1101101, 
    0b1111001, 
    0b0110011, 
    0b1011011, 
    0b1011111, 
    0b1110000, 
    0b1111111, 
    0b1111011  
};

vector<int> helper(int n) {
    vector<int> a;
    for(int i=0;i<7;i++) {
        int t = tmp[n]^(1<<i);
        for(int j=0;j<=9;j++) {
            if(tmp[j] == t) a.push_back(j);
        }
    }
    return a;
}

int helper1(int h1, int m1, int h2, int m2, int a, int b) {
    h1 %= 12;
    if(h1 == 0) h1 = 12;
    h2 %= 12;
    if(h2 == 0) h2 = 12;
    int hd = abs(h1 - h2);
    hd = min(hd, 12 - hd);
    int hm = hd*60;
    int hc = hm*a;
    int md = abs(m1 - m2);
    md = min(md, 60 - md);
    int mc = md*b;
    return hc + mc;
}

int main() {
    string s;
    cin >> s;
    int a,b;
    cin >> a >> b;
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    vector<vector<int>> d(4);
    string t = {s[0], s[1], s[3], s[4]};
    for (int i=0;i<4;i++) d[i] = helper(t[i] - '0');
    int ans = INT_MAX;
    string res = "";
    for (int i=0;i<4;i++) {
        for (auto it:d[i]) {
            string ns = s;
            ns[i+(i>=2?1:0)] = it + '0';
            int hh = stoi(ns.substr(0, 2));
            int mm = stoi(ns.substr(3, 2));
            if(hh>=1 && hh<=12 && mm>=0 && mm<=59) {
                int c = helper1(h, m, hh, mm, a, b);
                if(c<ans) {
                    ans = c;
                    res = ns;
                }
            }
        }
    }
    if (res.empty()) cout << "No closest valid time possible";
    else cout << res;
}
