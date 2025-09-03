#include <bits/stdc++.h>
using namespace std;

bool isKaprekar(long long n) {
    if (n == 1) return true;

    long long sq_n = n * n;
    int count_digits = to_string(sq_n).length();

    for (int r_digits = 1; r_digits < count_digits; r_digits++) {
        long long eq_parts = 1;
        for (int i = 0; i < r_digits; i++) eq_parts *= 10; // avoid pow()

        if (eq_parts == n) continue;

        long long left = sq_n / eq_parts;
        long long right = sq_n % eq_parts;

        if (left + right == n)
            return true;
    }

    return false;
}

int main() {
    cout << "First few Kaprekar Numbers:\n";
    for (int i = 1; i < 10000; i++) {
        if (isKaprekar(i)) cout << i << " ";
    }
    return 0;
}
