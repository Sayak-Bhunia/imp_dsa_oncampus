#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.resize(distance(a.begin(), it));
    if(a.size()<2) cout << -1 <<endl;
    else {
        cout << a[1] << " " <<  a[a.size()-2] <<endl;
    }
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int a = INT_MIN, b = INT_MIN;  //int a = Integer.MIN_VALUE, b = Integer.MIN_VALUE; <- for java
    int c = INT_MAX, d = INT_MAX;
    for(auto it:arr) {
        if(it>a) {
            b = a;
            a = it;
        }
        else if(it>b && it != a) b = it;
        if(it<c) {
            d = c;
            c = it;
        }
        else if(it<d && it != c) d = it;
    }
    cout << d << " " << b <<endl;
}
