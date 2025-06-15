#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int n) {
    int c = 0;
    for(int i=1;i<=n;i++) {
        if(i%2 == 0 && i%4 == 0 && i%8 == 0 && i%10 != 0) c++;
    }
    cout << c <<endl;
}

int main() {
    int n;
    cin >> n;
    helper(n);
}
