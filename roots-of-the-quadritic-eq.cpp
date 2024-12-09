#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void helper(double a, double b, double c) {
    if(a == 0) {
        cout << -1 << endl;
        return;
    }
    double d = b*b - 4*a*c;
    if(d>0) {
        double r1 = (-b + sqrt(d))/(2*a);
        double r2 = (-b - sqrt(d))/(2*a);
        cout << "The roots are real and distinct: " <<endl;
        cout << r1 << endl;
        cout << r2 << endl;
    } 
    else if(d == 0) {
        double r = -b/(2*a);
        cout << "The roots are real and equal: " <<endl;
        cout << r << endl;
    } 
    else {
        double real = -b/(2*a);
        double img = sqrt(-d)/(2*a);
        cout << "The roots are complex: " << endl;
        cout << "r1 = " << real << " + " << img << "i" << endl;
        cout << "r2 = " << real << " - " << img << "i" << endl;
    }
}

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    helper(a, b, c);
}
