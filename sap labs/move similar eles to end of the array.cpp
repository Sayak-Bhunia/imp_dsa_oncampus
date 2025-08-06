#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveMostFrequentToEnd(vector<int>& a) {
        unordered_map<int, int> mp;
        for(auto it:a) mp[it]++;
        int mx = 0, mxe = a[0];
        for(auto it:mp) {
            if(it.second<mx) {
                mx = it.second;
                mxe = it.first;
            }
        }
        int j = 0;
        for(int i=0;i<a.size();i++) {
            if(a[i] != mxe) swap(a[i], a[j++]);
        }
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 4, 4, 2, 4};
    sol.moveMostFrequentToEnd(nums);

    for(int n : nums) cout << n << " ";
    return 0;
}
