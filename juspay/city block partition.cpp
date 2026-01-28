#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> grid(2);
    cin >> grid[0] >> grid[1];
    int res = 0;
    for(int i=1;i<n-1;i++) {
        if((grid[0][i] == '.')^(grid[1][i] == '.')) {
            int r = (grid[0][i] == '.')? 0:1;
            if(grid[r][i-1] == '.' && grid[1-r][i-1] == '.' && grid[r][i+1] == '.' && grid[1-r][i+1] == '.') res++;
        }
    }
    cout << res <<endl;
}
