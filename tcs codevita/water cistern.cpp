#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793

int main() {
    double r,h,s,d,g, res = 0.0;
    cin >> r >> h >> s;
    cin >> d >> g;
    if(d>0) {
        double x1 = 0.0, y1 = s, x2 = 2.0*PI*r*(g/360.0), y2 = d;
        res = hypot(x2 - x1, y2 - y1);
    }
    else {
        double a = -d;
        double bef = (g*PI)/180.0;
        double dis = sqrt(r*r + a*a - 2*r*a*cos(bef));
        res = s + dis;
    }
    cout << round(res) <<endl;
}
