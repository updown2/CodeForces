#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define a first
#define b second
#define mp make_pair
#define eb emplace_back
#define w cout
#define e endl
#define s <<" "<<
#define int long long
//#define c <<" : "<<e;

const int MAXN = 1001, MOD = 1000000007;

int N, M, K, out = 1, p2[60], p[60], use[60];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    if (K == -1 && M%2 != N%2) {w<< 0<<e; return 0;}
    p2[0] = 2; For(i, 1, 60) {p2[i] = (p2[i-1]*p2[i-1])%MOD;}
    use[0] = 1; For(i, 1, 60) use[i] = 2*use[i-1];
    For (i, 0, 60) if ((N-1) & use[i]) {out *= p2[i]; out %= MOD;}
    p[0] = out; For (i, 1, 60) {p[i] = (p[i-1]*p[i-1])%MOD;}
    out = 1;
    For (i, 0, 60) if ((M-1) & use[i]) {out *= p[i]; out %= MOD;}
    w<< out<<e;
}
