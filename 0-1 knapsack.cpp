#include <bits/stdc++.h> 

int knapsack(vector<int> wt, vector<int> val, int n, int MW) {
	vector<int> prev(MW+1, 0);
	for(int i=wt[0];i<=MW;i++) prev[i] = val[0];
	for(int idx=1;idx<n;idx++) {
		for(int W=MW;W>=0;W--) {
			int nt = prev[W];
			int t = INT_MIN;
			if(wt[idx]<=W) t = val[idx] + prev[W-wt[idx]];
			prev[W] = max(t, nt);
		}
	}
	return prev[MW];
}
