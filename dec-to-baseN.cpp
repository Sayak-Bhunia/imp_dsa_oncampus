#include <bits/stdc++.h>
#define lint long long 
using namespace std;

char* DectoNBase(int n, int num) {
    string c = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res = "";
    while(num != 0) {
        res = c[num%n] + res;
        num /= n;
    }
    char* s = new char[res.size()+1];
    strcpy(s, res.c_str());
    return s;
}

int main() {   
    int n, num;
    cin >> n >> num;
    char* result = DectoNBase(n, num);
    cout << result << endl;
} 
