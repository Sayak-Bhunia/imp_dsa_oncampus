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
    vector<lint> d;
    for(lint i=1;i<=sqrt(n);i++) {
        if(n%i == 0) {
            d.push_back(i);
            if(i != n/i) d.push_back(n/i);
        }
    }
    int c = 0;
    for(auto it:d) {
        if(it != 1 && helper1(it)) c++;
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
