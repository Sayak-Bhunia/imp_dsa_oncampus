#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> countStarsBetweenBars(const string &s, const vector<int> &startIndex, const vector<int> &endIndex) {
    int n = s.length();
    vector<int> pref(n, 0), lb(n, -1), rb(n, -1);
    vector<int> res;
    int stars = 0, lastbar = -1;
    for(int i=0;i<n;i++) {
        if(s[i] == '|') lastbar = i;
        lb[i] = lastbar;
    }
    lastbar = -1;
    for(int i=n-1;i>=0;i--) {
        if(s[i] == '|') lastbar = i;
        rb[i] = lastbar;
    }
    bool f = false;
    for(int i=0;i<n;i++) {
        if(s[i] == '|') f = true;
        else if(s[i] == '*' && f) stars++;
        pref[i] = stars;
    }
    for(int i=0;i<startIndex.size();i++) {
        int s = rb[startIndex[i]], e = lb[endIndex[i]];
        if(s == -1 || e == -1 || s>=e) res.push_back(0);
        else res.push_back(pref[e] - pref[s]);
    }
    return res;
}

int main() {
    string s = "|**|*|";
    vector<int> startIndex = {0, 0};
    vector<int> endIndex = {4, 5};

    vector<int> result = countStarsBetweenBars(s, startIndex, endIndex);
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
