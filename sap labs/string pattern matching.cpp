#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for transform
using namespace std;

void kmp(string &t, vector<int> &lps) {
    lps[0] = 0;
    int i = 1, j = 0;
    while(i<t.length()) {
        if(t[i] == t[j]) lps[i++] = ++j;
        else {
            if(j != 0) j = lps[j-1];
            else lps[i++] = 0;
        }
    }
}

// s -> given string
// t -> pattern to be matched

vector<int> search(string &s, string &t) {
    int n = s.length(), m = t.length();
    for(auto &it:s) it = toupper(it);
    for(auto &it:t) it = toupper(it);
    vector<int> lps(m), res;
    kmp(t, lps);
    int i = 0, j = 0;
    while(i<n) {
        if(s[i] == t[j]) {
            i++;
            j++;
            if(j == m) {
                res.push_back(i-j);
                j = lps[j-1];
            }
        }
        else {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
    return res;
}

int main() {
    string txt = "BACDGABCDA";
    string pat = "abcd";

    vector<int> res = search(txt, pat);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}
