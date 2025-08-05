#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void findAllValidDivisions(vector<int>& arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    vector<int> a;
    vector<int> b = arr;
    int sum1 = 0;
    int sum2 = accumulate(arr.begin(), arr.end(), 0);
    for(int i=0;i<arr.size()-1;i++) {
        a.push_back(arr[i]);
        sum1 += arr[i];
        b.erase(b.begin());
        sum2 -= arr[i];
        if(sum1>sum2 && a.size()<b.size()) {
            for(auto it:a) cout << it << " ";
            cout <<endl;
            for(auto it:b) cout << it << " ";
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 5, 1, 6};

    findAllValidDivisions(arr);

    return 0;
}
