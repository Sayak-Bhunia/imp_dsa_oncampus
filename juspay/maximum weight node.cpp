// User function Template for C++
#define lint long long int
class Solution {
  public:
    int maxWeightCell(vector<int> &a) {
        lint res = -1, mx = -1;
        vector<int> wt(a.size(), 0);
        for(int i=0;i<a.size();i++) {
            if(a[i] != -1) wt[a[i]] += i;
        }
        for(int i=0;i<a.size();i++) {
            if(wt[i]>mx || (wt[i] == mx && i>res)) {
                mx = wt[i];
                res = i;
            }
        }
        return res;
    }
};
