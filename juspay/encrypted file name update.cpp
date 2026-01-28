#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k<n) {
        cout << "-1\n";
        return 0;
    }
    string t = s;
    sort(t.begin(), t.end());
    char mn = t[0];
    vector<char> chars(t.begin(), t.end());
    if(k>n) {
        cout << s;
        for(int i=0;i<k-n;i++) cout << mn;
        cout <<endl;
        return 0;
    }
    for(int i=n-1;i>=0;i--) {
        for(char c:chars) {
            if(c>s[i]) {
                cout << s.substr(0, i) << c;
                for(int j=i+1;j<n;j++) cout << mn;
                cout <<endl;
                return 0;
            }
        }
    }
    cout << "-1" <<endl;
}
