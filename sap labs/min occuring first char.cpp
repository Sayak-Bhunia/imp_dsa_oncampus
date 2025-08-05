#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

char minOccurringChar(const string& s) {
    unordered_map<char, int> mp;
    for(auto it:s) mp[it]++;
    int mn = INT_MAX;
    char res = '\0';
    for(auto it:s) {
        if(mp[it]<mn && it != ' ') {
            mn = mp[it];
            res = it;
        }
    }
    return res;
}

int main() {
    string s = "test sample";
    cout << "Minimum occurring character: " << minOccurringChar(s) << endl;
    return 0;
}
