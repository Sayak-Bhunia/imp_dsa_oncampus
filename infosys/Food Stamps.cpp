#include<bits/stdc++.h>
using namespace std;
#define lint long long int
int main() {
    int n;
    lint m;
    cin >> n >> m;
    vector<lint> v(n), d(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> d[i];
    priority_queue<lint> pq;
    for(int i=0;i<n;i++) {
        lint curr = v[i];
        lint t = 1;
        while(curr>0) {
            pq.push(curr);
            t++;
            curr = v[i]-d[i]*(t-1);
        }
    }
    lint res = 0;
    while(m-- && !pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    cout << res <<endl;
}
