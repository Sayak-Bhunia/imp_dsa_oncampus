#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

string helper(int n) {
    string ch = "0123456789ABCDEF", res;
    if(n == 0) return "00";
    while(n != 0) {
        res = ch[n%16] + res;
        n /= 16;
    }
    if(res.length() == 1) res = "0" + res;
    return res;
}

void convertToIpv6(string ipv4address) {
    vector<int> res;
    string s;
    for(auto it:ipv4address) {
        if(it == '.') {
            res.push_back(stoi(s));
            s = "";
        }
        else s += it;
    }
    res.push_back(stoi(s));
    if(res[0] == 127) {
        cout << "::1" <<endl;
        return;
    }
    string a = helper(res[0]) + helper(res[1]);
    string b = helper(res[2]) + helper(res[3]);
    cout << "::FFFF:" << a << ":" << b <<endl;
}

int main() {
    convertToIpv6("192.168.10.92");  // Output: ::FFFF:C0A8:0A5C
    convertToIpv6("127.0.0.1");      // Output: ::1
    return 0;
}
