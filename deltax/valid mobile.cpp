#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

bool isValidMobileNumber(const string& number) {
    int n = number.length();
    for(auto it:number) {
        if(isalpha(it)) return false;
    }
    if(n == 10) {
        if(number[0]>='6' && number[0]<='9') return true;
    }
    else if(n == 11) {
        if(number[0] == '0' && number[1]>='6' && number[1]<='9') return true;
    }
    else if(n == 12) {
        if(number[0] == '9' && number[1] == '1' && number[2]>='6' && number[2]<='9') return true;
    }
    return false;
}

int main() {
    string mobile;
    cout << "Enter Mobile Number: ";
    cin >> mobile;

    if (isValidMobileNumber(mobile)) {
        cout << "Valid Mobile Number" << endl;
    } else {
        cout << "Invalid Mobile Number" << endl;
    }

    return 0;
}
