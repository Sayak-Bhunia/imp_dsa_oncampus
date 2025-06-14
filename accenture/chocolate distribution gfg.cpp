class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(), a.end());
        int n = a.size();
        int mn = INT_MAX;
        for(int i=0;i<=n-m;i++) mn = min(mn, a[i+m-1] - a[i]);
        return mn;
    }
}; 
