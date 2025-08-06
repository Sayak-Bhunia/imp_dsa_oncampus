#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeInWindow(vector<int>& arr, int k) {
    vector<int> res;
    int n = arr.size();
    for(int i=0;i<=n-k;i++) {
        bool f = false;
        for(int j=i;j<i+k;j++) {
            if(arr[j]<0) {
                res.push_back(arr[j]);
                f = true;
                break;
            }
        }
        if(!f) res.push_back(0);
    }
    return res;
}

vector<int> firstNegativeInWindow(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> res;
    int n = arr.size();
    for(int i=0;i<n;i++) {
        if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
        if(arr[i]<0) dq.push_back(i);
        if(i>=k-1) {
            if(!dq.empty()) res.push_back(arr[dq.front()]);
            else res.push_back(0);
        }
    }
    return res;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> result = firstNegativeInWindow(arr, k);

    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
