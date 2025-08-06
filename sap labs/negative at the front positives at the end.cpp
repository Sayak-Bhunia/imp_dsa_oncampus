#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void rearrangeArray(vector<int>& arr) {
    int i = 0, j = arr.size() - 1;
    while(i<=j) {
        if(arr[i]<0 && arr[j]<0) i++;
        else if(arr[i]>0 && arr[j]<0) swap(arr[i++], arr[j--]);
        else if(arr[i]>0 && arr[j]>0) j--;
        else {
            i++;
            j--;
        }
    }
}

void rearrangeArray(vector<int>& arr) {
    vector<int> a, b;
    for(auto it:arr) {
        if(it<0) a.push_back(it);
        else b.push_back(it);
    }
    vector<int> res;
    for(int i=0;i<a.size();i++) res.push_back(a[i]);
    for(int i=0;i<b.size();i++) res.push_back(b[i]);
    arr = res;
}

int main() {
    vector<int> arr = {1, 2, -3, 4, -4, -5};

    rearrangeArray(arr);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
