#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
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
const int MAXN = 300000, INF = 10000000000;
//Global Variables
int N, M, x[MAXN], y[MAXN], prex[MAXN], posty[MAXN], out[MAXN];
pair<int, int> d[MAXN]; /// (diff, ind)

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffi {cin >> x[i] >> y[i]; d[i] = mp(x[i]-y[i], i);}
    sort(d, d+N);
    prex[0] = x[d[0].b];
    For (i, 1, N) prex[i] = prex[i-1] + x[d[i].b];
    posty[N-1] = y[d[N-1].b];
    for (int i=N-2; i>=0; i--) posty[i] = posty[i+1] + y[d[i].b];
    //ffi w<< d[i].a s prex[i] s posty[i]<<e;
    ffi {
        if (i == 0) out[d[i].b] = x[d[i].b]*(N-i-1)+posty[i+1];
        else if (i == N-1) out[d[i].b] = y[d[i].b]*i + prex[i-1];
        else out[d[i].b] = x[d[i].b]*(N-i-1)+posty[i+1] + y[d[i].b]*i + prex[i-1];
    }
    ffj {
        int a, b; cin >> a >> b; a--; b--;
        if (x[a] - y[a] < x[b] - y[b]) {
            out[a] -= x[a] + y[b];
            out[b] -= x[a] + y[b];
        }
        else {
            out[a] -= x[b] + y[a];
            out[b] -= x[b] + y[a];
        }
    }
    ffi w<< out[i]<< " "; w<<e;
}
