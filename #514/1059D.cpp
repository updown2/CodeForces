#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K+1)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
#define double long double
//500,000,000 operations
const int MAXN = 100000, INF = 1000000000000000000;
//Global Variables
int N, x[MAXN], y[MAXN], big;
pair<double, double> ranges[MAXN];

bool works(double r) {
    ffi {
        ranges[i].a = x[i] - sqrt(r*r-(r-y[i])*(r-y[i]));
        ranges[i].b = x[i] + sqrt(r*r-(r-y[i])*(r-y[i]));
    }
    double l = ranges[0].a, ri = ranges[0].b;
    ffi {
        l = max(l, ranges[i].a);
        ri = min(ri, ranges[i].b);
    }
    return ri >= l;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi cin >> x[i] >> y[i];
    bool low;
    if (y[0] < 0) low = true;
    else low = false;
    ffi {
        if (low && y[i] > 0) {w<< -1<<e; return 0;}
        if (!low && y[i] <0) {w<< -1<<e; return 0;}
        if (low) y[i]*= -1;
        big = max(big, y[i]);
    }
    double a = big/2.0, b = INF;
    while (abs(a-b)/b > .0000001) {
        double mid = (a+b)/2;
        if (works(mid)) b = mid;
        else a = mid;
    }
    w<< fixed << setprecision(7)<<a<<e;
}
