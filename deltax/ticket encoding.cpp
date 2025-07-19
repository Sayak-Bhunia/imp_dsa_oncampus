// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string generateTicketCode(int n) {
    string res = "A";
    for(int i=2;i<=n;i++) {
        string tmp = "";
        int c = 0;
        char ch = res[0];
        for(int j=0;j<res.length();j++) {
            if(res[j] == ch) c++;
            else {
                tmp += to_string(c) + ch;
                ch = res[j];
                c = 1;
            }
        }
        tmp += to_string(c) + ch;
        res = tmp;
    }
    return res;
}

int main()
{
    int N = 4;

    // Generate the ticket code for N
    string ticketCode = generateTicketCode(N);

    // Output the ticket code
    cout << ticketCode << endl;

    return 0;
}
