#include <iostream>
using namespace std;

// Function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;  // Extract the last digit and add it to the sum
        num /= 10;        // Remove the last digit
    }
    return sum;
}

// Function to check if a number is a Harshad number
bool isHarshadNumber(int num) {
    if (num == 0) return false; // Special case: 0 is not considered a Harshad number
    int digitSum = sumOfDigits(num);
    return (num % digitSum == 0); // Check divisibility
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isHarshadNumber(num)) {
        cout << num << " is a Harshad number." << endl;
    } else {
        cout << num << " is not a Harshad number." << endl;
    }

    return 0;
}
