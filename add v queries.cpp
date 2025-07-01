#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    string s;
    int val;
    while(k--) {
        cin >> s;
        if(s == "add") {
            cin >> val;
            if(maxHeap.empty() || val<=maxHeap.top()) maxHeap.push(val);
            else minHeap.push(val);
            if(maxHeap.size()>minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if(minHeap.size()>maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else if(s == "get") {
            double m;
            if(maxHeap.size() == minHeap.size()) m = (maxHeap.top() + minHeap.top())/2.0;
            else m = maxHeap.top();
            cout << setprecision(1) << m <<endl;
        }
    }
}
