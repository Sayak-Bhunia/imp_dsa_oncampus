#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int countSamePositionAfterReverse(const string& s) {
    int c = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == s[n - 1 - i]) count++;
    }

    return count;
}

int main() {
    string input = "Geeta";
    int result = countSamePositionAfterReverse(input);
    cout << result << endl;
    return 0;
}
