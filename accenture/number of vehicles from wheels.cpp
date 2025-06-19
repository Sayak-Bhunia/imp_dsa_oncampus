#include <bits/stdc++.h>
#define lint long long
using namespace std;

int helper(int v, int w) {
    int tw = ((4*v) - w)/2; //eta te joto bachabe setae max 2 wheeler hye jabe
    int fw = v - tw; // bakita 4 wheeler hye jabe
    cout << tw << " " << fw <<endl;
}

int main() {
    int v,w;
    cin >> v >> w;
    helper(v, w);
}
