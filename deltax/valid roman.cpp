#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

// Add validation inside the same function

int romanToInt(string s) {
    int n = s.length(), sum = 0, c = 1;
    if(n == 0) return -1;
    string t = "VLD";
    int last = mp[s[n-1]];
    for(int i=0;i<n;i++) {
        if(mp.find(s[i]) == mp.end()) return -1;
        if(i>0 && s[i] == s[i-1]) {
            c++;
            if(t.find(s[i]) != string::npos || c>3) return -1;
        }
        else c = 1;
        if(i<n-1 && mp[s[i]]<mp[s[i+1]]) {
            char a = s[i], b = s[i+1];
            if((a == 'I' && (b == 'V' || b == 'X')) || (a == 'X' && (b == 'L' || b == 'C')) || (a == 'C' && (b == 'D' || b == 'M'))) return -1;
            sum -= mp[s[i]];
        }
        else if(i<n-1) sum += mp[s[i]];
    }
    sum += last;
    return sum;
}

int main() {
    string s;
    cin >> s;

    int result = romanToInt(s);
    if (result == -1) cout << "Invalid" << endl;
    else cout << result << endl;

    return 0;
}
