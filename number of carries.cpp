#include <bits/stdc++.h>
#define lint long long 
using namespace std;

int helper(int a, int b) {
    int cr = 0, sum = 0, c = 0;
    while(a != 0 && b != 0) {
        sum  = cr + a%10 + b%10;
        if(sum>9) {
            cr = 1;
            c++;
        }
        else cr = 0;
        a /= 10;
        b /= 10;
    }
    return c;
}

int main() {   
    int a, b;
    cin >> a >> b;
    cout << helper(a, b) <<endl;
} 
