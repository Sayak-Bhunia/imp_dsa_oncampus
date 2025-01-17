#include <bits/stdc++.h>
#define lint long long 
using namespace std;

struct Complex {
    float real, img;
};

Complex add(Complex &a, Complex &b) {
    Complex sum;
    sum.real = a.real + b.real;
    sum.img = a.img + b.img;
    return sum;
}

int main() {   
    Complex a, b, sum;
    cin >> a.real >> a.img >> b.real >> b.img;
    sum = add(a, b);
    cout << sum.real << "+" << sum.img << "i";
}
