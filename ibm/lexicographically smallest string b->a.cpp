#include <bits/stdc++.h>
using namespace std;

string lexicographicallySmallest(string s) {
    int n = s.length();
    bool f = false;
    for(int i=0;i<n;i++) {
        if(s[i] != 'a') {
            for(int j=i;j<n && s[j] != 'a';j++) s[j] -= 1;
            f = true;
            break;
        }
    }
    if(!f) s[n-1] = 'z';
    return s;
}

int main() {
    string s = "hackerrank";
    cout << lexicographicallySmallest(s) << endl; 
    return 0;
}
