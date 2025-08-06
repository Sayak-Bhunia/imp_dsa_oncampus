#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int needle, haystack;
    cin >> needle >> haystack;
    // while(haystack != 0) {
    //     if(haystack%10 == needle) c++;
    //     haystack /= 10;
    // }
    string t = to_string(haystack);
    int c = count(t.begin(), t.end(), needle + '0');
    cout << c <<endl;
}
