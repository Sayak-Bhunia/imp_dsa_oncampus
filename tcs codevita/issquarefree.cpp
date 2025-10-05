#include <bits/stdc++.h>
#define lint long long int 
using namespace std;

bool helper1(int n) {
    for(lint i=2;i<=sqrt(n);i++) {
        if(n%(i*i) == 0) return false;
    }
    return true;
}

int helper(lint n) {
    int c = 0;
    for(lint i=2;i<=sqrt(n);i++) {
        if(n%i == 0) {
            if(helper1(i)) c++;
            if(i != n/i && helper1(n/i)) c++;
        }
    }
    return c;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
    	lint n;
    	cin >> n;
    	cout << helper(n) <<endl;
    }
}
