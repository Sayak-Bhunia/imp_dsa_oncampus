#include <bits/stdc++.h>
#define lint long long
using namespace std;

bool helper(int n) {
    if(n == 1) return true;
    else if(n<10) return false;
    else {
        int sum = 0;
        while(n != 0) {
            sum += n%10;
            n /= 10;
        }
        return helper(sum);
    }
}

int main() {
    int n;
    cin >> n;
    if(helper(n)) cout << "true" <<endl;
    else cout << "false" <<endl;
}
