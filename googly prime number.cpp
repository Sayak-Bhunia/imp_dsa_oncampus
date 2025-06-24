#include <bits/stdc++.h>
#define lint long long
using namespace std;

bool prime(int n) {
    if(n<=1) return false;
    for(int i=2;i<=sqrt(n);i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int helper(int n) {
    int sum = 0;
    while(n != 0) {
        sum += n%10;
        n /= 10;
    }
    if(prime(sum)) cout << "prime" <<endl;
    else cout << "non prime" <<endl;
}

int main() {
    int n;
    cin >> n;
    helper(n);
}
