#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

vector<long long> dijkstra(vector<vector<int>> &graph, int c) {
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
    pq.push({0, c});
    vector<long long> res(graph.size(), INT_MAX);
    res[c] = 1;
    while(!pq.empty()) {
        long long tmp = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:graph[node]) {
            if(tmp+1<res[it]) {
                res[it] = tmp + 1;
                pq.push({tmp + 1, it});
            }
        }
    }
    return res;
}

int minimumWeight(int n, vector<int> &edges, int c1, int c2) {
    vector<vector<int>> graph(n);
    for(int i=0;i<n;i++) {
        if(edges[i] != -1) graph[i].push_back(edges[i]);
    }
    vector<long long> a(n, INT_MAX), b(n, INT_MAX);
    a = dijkstra(graph, c1);
    b = dijkstra(graph, c2);
    int node = -1;
    long long dst = INT_MAX;
    for(int i=0;i<n;i++) {
        if(a[i] == INT_MAX || b[i] == INT_MAX) continue;
        if(dst>a[i]+b[i]) {
            dst = a[i] + b[i];
            node = i;
        }
    }
    return node;
}

int main()
{
    int n;
    cin >> n;

    vector<int> edges(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> edges[i];
    }

    int C1, C2;
    cin >> C1 >> C2;

    int nearestMeetingCell = minimumWeight(n, edges, C1, C2);
    cout << nearestMeetingCell << endl;

    return 0;
}
