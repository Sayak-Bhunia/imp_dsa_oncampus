#include <bits/stdc++.h>
using namespace std;

// Greedy function to check if it's possible to place K patients with at least 'dist' apart
bool isPossible(const vector<int>& rooms, int k, int mid) {
    int c = 1, last = rooms[0];
    for(int i=1;i<rooms.size();i++) {
        if(rooms[i] - last>=mid) {
            c++;
            last = rooms[i];
            if(c>=k) return true;
        }
    }
    return false;
}

// Function to compute the maximum minimum distance
int maxMinDistance(vector<int>& rooms, int k) {
    int n = rooms.size();
    sort(rooms.begin(), rooms.end());
    int l = 1, r = rooms[n-1] - rooms[0], res = 0;
    while(l<=r) {
        int mid = l + (r - l)/2;
        if(isPossible(rooms, k, mid)) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> rooms(n);
    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }

    cout << maxMinDistance(rooms, k) << endl;
    return 0;
}
