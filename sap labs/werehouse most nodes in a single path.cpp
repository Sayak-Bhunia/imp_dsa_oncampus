#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> tree;
unordered_set<int> requested;
int mx = 0;

void dfs(int node, int parent, int c) {
    if(requested.count(node)) c++;
    mx = max(mx, c);
    for(auto it:tree[node]) {
        if(it != parent) dfs(it, node, mx);
    }
}

int main() {
    int num; cin >> num; // Total nodes (including warehouse)
    
    int k; cin >> k; // Number of requested outlets
    requested.clear();
    for (int i = 0; i < k; i++) {
        int outletId; cin >> outletId;
        requested.insert(outletId);
    }

    int numR, conOutlet;
    cin >> numR >> conOutlet; // numR = num - 1 (since it's a tree), conOutlet always 2

    tree.resize(num); // initialize tree with 'num' nodes
    for (int i = 0; i < numR; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(0, -1, 0); // Start from warehouse (node 0)

    cout << mx << endl;
}
