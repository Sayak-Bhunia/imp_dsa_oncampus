#include <bits/stdc++.h>
using namespace std;

const vector<int> tmp = {
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

int diff(int a, int b) {
    return __builtin_popcount(tmp[a]^tmp[b]);
}

string helper(int h, int m) {
    char ch[6];
    snprintf(ch, 6, "%02d:%02d", h, m);
    return string(ch);
}

int main() {
    string s;
    int a, b;
    cin >> s >> a >> b;
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    vector<int> orig = {
        s[0] - '0',
        s[1] - '0',
        s[3] - '0',
        s[4] - '0'
    };
    int mn = INT_MAX;
    string res = "";
    for(int nh=1;nh<=12;nh++) {
        for(int nm=0;nm<60;nm++) {
            int d0 = nh/10;
            int d1 = nh%10;
            int d2 = nm/10;
            int d3 = nm%10;
            vector<int> cand = {d0, d1, d2, d3};
            int dc = 0;
            for(int i=0;i<4;i++) dc += diff(orig[i], cand[i]);
            if(dc == 1) {
                int dh = abs(h - nh);
                if(dh>6) dh = 12 - dh;
                int dm = abs(m - nm);
                if(dm>30) dm = 60 - dm;
                int c = dh*a + dm*b;
                if(c<mn) {
                    mn = c;
                    res = helper(nh, nm);
                }
            }
        }
    }
    if (res == "") cout << "No closest valid time possible";
    else cout << res;
}
