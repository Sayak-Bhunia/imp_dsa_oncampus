#include <bits/stdc++.h>
#define lint long long int 
using namespace std;

lint helper(lint a) {
    lint p = 1, b = 2;
    while(a>0) {
        if(a&1) p = (p*b)%100;
        b = (b*b)%100;
        a >>= 1;
    }
    return p;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	lint sum = 0;
    	for(int i=0;i<n;i++) {
    	    lint x;
    	    cin >> x;
    	    lint b = x%20;
    	    if(b == 0) b = 20;
    	    sum = (sum+helper(b))%100;
    	}
    	cout << sum%100 <<endl;
    }
}
