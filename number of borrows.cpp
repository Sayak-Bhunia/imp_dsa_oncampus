#include <bits/stdc++.h>
#define lint long long 
using namespace std;

int helper(int a, int b) {
    int br = 0, c = 0;
    while(a != 0 || b != 0) {
        if(a%10<b%10 + br) {
            br = 1;
            c++;
        }
        else br = 0;
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
