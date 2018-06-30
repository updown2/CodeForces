/*
sort points by angle from origin
take 360-angle btwn two consecutive points
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=100000, INF=1000000000000000000;
///500,000,000
int N;
double ang[MAXN], PI, out;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    PI = acos(-1);
    w<< fixed << setprecision(6);
    cin >> N;
    ffi {
        int x, y; cin >> x >> y;
        ang[i] = atan(y/(double)x)*180/PI;
        if (x < 0) ang[i] += 180;
        if (ang[i] < 0) ang[i] += 360;
        //w<< x s y s ":" s ang[i]<<e;
    }
    sort(ang, ang+N);
    out = ang[N-1] - ang[0];
    For (i, 1, N) out = min(out, 360-(ang[i]-ang[i-1]));
    w<< out<<e;
}
