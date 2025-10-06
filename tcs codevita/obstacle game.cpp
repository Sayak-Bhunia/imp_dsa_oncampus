#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<vector<char>> grid(n, vector<char>(n));
	    pair<int, int> src{-1, -1}, dst{-1, -1};
	    for(int i=0;i<n;i++) {
	        for(int j=0;j<n;j++) {
	            cin >> grid[i][j];
	            if(grid[i][j] == 'A') src = {i, j};
	            if(grid[i][j] == 'D') dst = {i, j};
	        }
	    }
	    vector<pair<int, int>> d = {
	        {-1,-1}, {-1,0},
	        {-1,1}, {0,-1},        
	        {0,1}, {1,-1}, 
	        {1,0}, {1,1}
	    };
	    vector<vector<bool>> vis(n, vector<bool>(n, false));
	    vector<pair<int, int>> p;
	    bool f = false;
	    function<bool(int, int)> dfs = [&](int x, int y)->bool {
	        if(f) return true;
	        if(x == dst.first && y == dst.second) {
	            p.push_back({x, y});
	            f = true;
	            return true;
	        }
	        vis[x][y] = true;
    	    for(auto &it:d) {
    	        int nx = x + it.first, ny = y + it.second;
    	        if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
    	        if(vis[nx][ny]) continue;
    	        char ch = grid[nx][ny];
    	        if(ch == 'R' || ch == 'M' || ch == 'D') {
    	            if(dfs(nx, ny)) {
    	                p.push_back({x, y});
    	                return true;
    	            }
    	        }
    	    }
    	    return false;
	    };
	    dfs(src.first, src.second);
	    reverse(p.begin(), p.end());
	    for(int i=1;i<(int)p.size();i++) {
	        int x = p[i].first, y = p[i].second;
	        if(grid[x][y] == 'D') {
	            cout << "DESTINATION" <<endl;
	            break;
	        }
	        vector<char> res;
	        for(auto &it:d) {
	            int nx = x + it.first, ny = y + it.second;
	            if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
	            char ch = grid[nx][ny];
	            if(ch == 'S' || ch == 'L' || ch == 'W' || ch == 'T') res.push_back(ch);
	        }
	        if(res.empty()) cout << "NO HURDLES" <<endl;
	        else {
	            sort(res.begin(), res.end());
	            for(int j=0;j<res.size();j++) {
	                if(j) cout << " ";
	                cout << res[j];
	            }
	            cout <<endl;
	        }
	    }
	}
}
