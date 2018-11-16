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
const int MAXN = 5001, INF = 10000000000, MOD = 998244353;
//Global Variables
int L, R, K, dpc[19][2<<10][2], dps[19][2<<10][2], n[19], p10[19];

int cnt(int N) {
    int y = N;
    int len = 0;
    while (y>0) {len++; y/=10;}
    y = N;
    For (i, 1, len+1) {n[len-i+1] = y%10; y/=10;}
    //w<< N <<e; For(i, 0, len) w<< i c n[i]<<e;
    For (i, 0, len+1) For (j, 0, 2<<10) For (k, 0, 2) dpc[i][j][k] = dps[i][j][k] = 0;
    dpc[0][0][1] = 1;
    For (i, 0, len) For (j, 0, 2<<10) {
        int st = 0;
        if (i == 0) st = 1;
        For (k, st, 10) dpc[i+1][j|(1<<k)][0] += dpc[i][j][0];
        For (k, st, n[i+1]) dpc[i+1][j|(1<<k)][0] += dpc[i][j][1];
        dpc[i+1][j|(1<<n[i+1])][1] += dpc[i][j][1];
    }

    For (i, 0, len) For (j, 0, 2<<10) {
        //if (dpc[i][j][0] > 0) w<< "dpc:" s i s j s 0 c dpc[i][j][0]<<e;
        //if (dpc[i][j][1] > 0) w<< "dpc:" s i s j s 1 c dpc[i][j][1]<<e;
        //if (dps[i][j][0] > 0) w<< "dps:" s i s j s 0 c dps[i][j][0]<<e;
        //if (dps[i][j][1] > 0) w<< "dps:" s i s j s 1 c dps[i][j][1]<<e;
        int st = 0;
        if (i == 0) st = 1;
        For (k, st, 10)     dps[i+1][j|(1<<k)]     [0] += dps[i][j][0] + k*p10[len-i-1]*dpc[i][j][0], dps[i+1][j|(1<<k)][0] %= MOD;
        For (k, st, n[i+1]) dps[i+1][j|(1<<k)]     [0] += dps[i][j][1] + k*p10[len-i-1]*dpc[i][j][1], dps[i+1][j|(1<<k)][0] %= MOD;
                            dps[i+1][j|(1<<n[i+1])][1] += dps[i][j][1] + n[i+1]*p10[len-i-1]*dpc[i][j][1]; dps[i+1][j|(1<<n[i+1])][1] %= MOD;
    }

    int ret = 0;
    For (j, 0, 2<<10) For (k, 0, 2) {
        if (__builtin_popcount(j) <= K) ret += dps[len][j][k];
        //if (dps[len][j][k] > 0) w<< len s j s k c dps[len][j][k]<<e;
    }
    return ret;
}

int solve (int N) {
    int y = N;
    int len = 0;
    while (y>0) {len++; y/=10;}
    int ret = 0;
    For (i, 1, len) ret = (ret+cnt(p10[i]-1))%MOD;
    ret = (ret+cnt(N))%MOD;
    return ret;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    p10[0] = 1; For (i, 1, 20) p10[i] = p10[i-1]*10;
    cin >> L >> R >> K;
    w << (solve(R)-solve(L-1)+MOD)%MOD<<e;
}
