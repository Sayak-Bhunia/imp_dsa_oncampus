#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	vector<long long> c(n);
	for(int i=0;i<n;i++) cin >> c[i];
	int m = s.length();
	vector<vector<int>> v(n, vector<int>(26, 0));
	for(int i=0;i<n;i++) {
	    for(auto it:a[i]) v[i][it - 'a']++;
	}
	vector<vector<vector<int>>> r(n, vector<vector<int>>(m));
	vector<vector<vector<int>>> l(n, vector<vector<int>>(m));
	for(int i=0;i<n;i++) {
	    string t = a[i];
	    int p = t.size();
	    vector<int> q = v[i];
	    for(int j=0;j<m;j++) {
	        int mx = min(p, m - j);
	        vector<int> used(26), lsd;
	        for(int k=0;k<mx;k++) {
	            int ci = s[j+k] - 'a';
	            used[ci]++;
	            if(used[ci]>q[ci]) break;
	            lsd.push_back(j + k + 1);
	        }
	        r[i][j] = move(lsd);
	    }
	    for(int j=0;j<m;j++) {
	        int curr = j;
	        vector<int> lsd;
	        int last = curr;
	        for(auto it:t) {
	            if(curr<m && it == s[curr]) {
	                curr++;
	                if(curr>last) {
	                    lsd.push_back(curr);
	                    last = curr;
	                    if(curr == m) break;
	                }
	            }
	        }
	        l[i][j] = move(lsd);
	    }
	}
	vector<long long> dpr(m+1, 1e15), dpl(m+1, 1e15);
    dpr[m] = dpl[m] = 0;
	for(int i=m-1;i>=0;i--) {
	    long long res = 1e15;
	    for(int j=0;j<n;j++) {
	        auto &it = l[j][i];
	        if(!it.empty()) {
	            long long cost = c[j];
	            for(auto k:it) {
	                long long v = dpl[k];
	                if(v<1e15) {
	                    long long t = cost + v;
	                    res = min(res, t);
	                }
	            }
	        }
	    }
	    dpl[i] = res;
	    res = 1e15;
	    for(int j=0;j<n;j++) {
	        auto &it = r[j][i];
	        if(!it.empty()) {
	            long long cost = c[j];
	            for(auto k:it) {
	                long long v = dpr[k];
	                if(v<1e15) {
	                    long long t = cost + v;
	                    res = min(res, t);
	                }
	            }
	        }
	    }
	    dpr[i] = res;
	}
	if(dpr[0]>=1e15 || dpl[0]>=1e15) cout << "-1";
	else cout << dpl[0] - dpr[0];
}
