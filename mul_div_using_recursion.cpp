#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mul(int a, int b) {
    if(b == 0) return 0;
    else return a + mul(a, b-1);
}

int division(int a, int b) {
    if(b == 0) return -1;
    if(a<b) return 0;
    else return 1 + division(a-b, b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << mul(a, b) <<endl;
    cout << division(a, b) <<endl;
}
