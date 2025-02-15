#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {   
    int n = 5;
    vector<int> a(n), b(n);
    sortasc(a);
    sortasc(b);
    for(int i=0;i<n;i++) mn += 1ll*a[i]*b[i];
    cout << mn <<endl;
}
