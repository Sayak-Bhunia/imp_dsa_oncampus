#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int n) {
    if(n<=1) return 1;
    else return n*helper(n-1);
}

int main() {
    int n;
    cin >> n;
    cout << helper(n) <<endl;
}
