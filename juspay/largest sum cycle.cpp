// User function Template for C++
class Solution {
  public:
    int res = -1;
    void dfs(int node, vector<bool> &vis, unordered_map<int, int> &mp, vector<int> &path, vector<int> &Edge) {
        vis[node] = true;
        path.push_back(node);
        int adj = Edge[node];
        if(adj != -1 && !vis[adj]) {
            mp[adj] = mp[node] + 1;
            dfs(adj, vis, mp, path, Edge);
        }
        else if(adj != -1 && mp.count(adj)) {
            int sum = 0;
            for(int i=path.size()-1;i>=0;i--) {
                sum += path[i];
                if(path[i] == adj) break;
            }
            res = max(res, sum);
        }
        path.pop_back();
     }
    long long largestSumCycle(int N, vector<int> Edge) {
        // code here
        vector<bool> vis(N, 0);
        for(int i=0;i<N;i++) {
            if(!vis[i]) {
                unordered_map<int, int> mp;
                mp[i] = 1;
                vector<int> path;
                dfs(i, vis, mp, path, Edge);
            }
        }
        return res;
    }
};
