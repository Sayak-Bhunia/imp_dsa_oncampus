#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1001);
unordered_map<int, int> mp;
int c = 0, m;

void dfs(int node, int prev) {
    if(mp[node] == 1) prev++;
    else prev = 0;
    if(prev>m) return;
    if(adj[node].empty()) {
        c++;
        return;
    }
    for(auto it:adj[node]) dfs(it, prev);
}

int countValidPaths(vector<vector<int>>& edges, unordered_map<int, int>& nodeFlags, int maxObstacles) {
    mp = nodeFlags;
    m = maxObstacles;
    unordered_set<int> all, child;
    for(auto it:edges) {
        adj[it[0]].push_back(it[1]);
        all.insert(it[0]);
        all.insert(it[1]);
        child.insert(it[1]);
    }
    int root = -1;
    for(auto it:all) {
        if(!child.count(it)) {
            root = it;
            break;
        }
    }
    if(root == -1) return -1;
    dfs(root, 0);
    return c == 0? -1:c;
}

int main() {
    vector<vector<int>> edges = {
        {1, 2}, {1, 3},
        {2, 4}, {2, 5},
        {3, 6}
    };

    unordered_map<int, int> nodeFlags = {
        {1, 0}, {2, 0}, {3, 0},
        {4, 1}, {5, 0}, {6, 1}
    };

    int m = 1;

    cout << countValidPaths(edges, nodeFlags, m) << endl;  // Output: 3
    return 0;
}
