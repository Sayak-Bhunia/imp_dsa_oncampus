#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mul(int a, int b) {
    int c = 0;
    bool f = (a<0)^(b<0);
    a = abs(a);
    b = abs(b);
    while(b>0) {
        if(b&1) c += a;
        a <<= 1;
        b >>= 1;
    }
    return f? -c: c;
}

int division(int a, int b) {
    int c = 0;
    bool f = (a<0)^(b<0);
    a = abs(a);
    b = abs(b);
    while(a>=b) {
        a -= b;
        c++;
    }
    return f? -c : c;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << mul(a, b) <<endl;
    cout << division(a, b) <<endl;
}
