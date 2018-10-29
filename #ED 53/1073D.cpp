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
//500,000,000 operations
const int MAXN = 200000, INF = 10000000000;
//Global Variables
int N, T, a[MAXN], tot, out, del, sm = INF;
bool gone[MAXN];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T;
    ffi {cin >> a[i]; sm = min(sm, a[i]);}
    while (T >= sm) {
        tot = 0;
        ffi if (!gone[i]) tot += a[i];

        int x = T/tot;
        out += x*(N-del);
        T -= x*tot;
        ffi {
            if (!gone[i] && T >= a[i]) {
                out++;
                T -= a[i];
            }
            else if (!gone[i]) {
                gone[i] = true;
                del++;
            }
        }
    }
    w<< out<<e;
}
