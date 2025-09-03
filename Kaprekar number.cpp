#include <bits/stdc++.h>
using namespace std;

bool isKaprekar(long long n) {
    if (n == 1)  // 1 is a Kaprekar number
        return true;

    long long sq = n * n;
    int d = to_string(n).length();  // number of digits in n

    long long right = sq % (long long)pow(10, d);
    long long left = sq / (long long)pow(10, d);

    return (left + right) == n;
}

int main() {
    long long n;
    cin >> n;

    if (isKaprekar(n))
        cout << n << " is a Kaprekar number\n";
    else
        cout << n << " is NOT a Kaprekar number\n";

    return 0;
}
