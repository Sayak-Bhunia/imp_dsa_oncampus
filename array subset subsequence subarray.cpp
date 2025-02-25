#include <bits/stdc++.h>
#define lint long long 
using namespace std;

// isSubset
int main() {   
    int n,m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    unordered_set<int> set(a.begin(), a.end());
    bool f = false;
    for(auto it:b) {
        if(set.find(it) == set.end()) {
            f = true;;
            break;
        }
    }
    if(f) cout << "NO" <<endl;
    else cout << "YES" <<endl;
}

bool isSubsequence(vector<int>& a, vector<int>& b) {
    int n = a.size(),  m = b.size();
    int i = 0, j = 0;
    while(i<n && j<m) {
        if(a[i] == b[j]) j++;
        i++;
    }
    return (j == m);  
}

bool isSubarray(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    for(int i=0;i<=n-m;i++) {
        bool match = true;
        for(int j=0;j<m;j++) {
            if(A[i+j] != B[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false; 
}
