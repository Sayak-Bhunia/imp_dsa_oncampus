#include <bits/stdc++.h>
#define lint long long 
using namespace std;

int main() {   
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
    unordered_map<int, int> mp;
    for(auto it:a) {
        int x = it.first;
        int y = it.second;
        if(mp.find(y) != mp.end() && mp[y] == x) {
            cout << "(" << y << "," << x << ")" <<endl;
            cout << "(" << x << "," << y << ")" <<endl;
        }
        else mp[x] = y;
    }
}

import java.util.*;

public class Main {

    public static void findSymmetricPairs(int[][] a) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int[] it:a) {
            int x = it[0], y = it[1];
            if(mp.containsKey(y) && mp.get(y) == x) System.out.println("(" + x + ", " + y + ")");
            else mp.put(x, y);
        }
    }

    public static void main(String[] args) {
        int[][] pairs = {
            {1, 2}, {3, 4}, {5, 6}, {2, 1}, {4, 3}
        };

        findSymmetricPairs(pairs);
    }
}

