#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    string line;
    getline(cin, line);

    // Remove braces and spaces
    line.erase(remove(line.begin(), line.end(), '{'), line.end());
    line.erase(remove(line.begin(), line.end(), '}'), line.end());

    // Replace commas with spaces
    replace(line.begin(), line.end(), ',', ' ');

    stringstream ss(line);
    int x;
    while (ss >> x) v.push_back(x);

    cout << "You entered: ";
    for (int n : v) cout << n << " ";
    cout << "\n";
}
