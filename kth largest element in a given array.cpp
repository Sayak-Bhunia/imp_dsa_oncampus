class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        return a[a.size()-k];
    }
};
