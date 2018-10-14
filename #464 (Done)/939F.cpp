#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 100001, MAXK = 101, INF = 1000000000;
//Global Variables
int N, K, inp[MAXK][2], dp[MAXK][MAXN], tree[MAXK][4*MAXN+1]; /// mintree

void build(int x, int L, int R, int row) {
    if (L == R) {
        tree[row][x] = dp[row][L];
        return;
    }
    build(x*2, L, (L+R)/2, row), build(x*2+1, (L+R)/2+1, R, row);
    tree[row][x] = min(tree[row][x*2], tree[row][x*2+1]);
}
int query(int x, int L, int R, int oL, int oR, int row) {
    if (oR < L || R < oL) return INF;
    if (oL <= L && R <= oR) return tree[row][x];
    return min(query(x*2, L, (L+R)/2, oL, oR, row), query(x*2+1, (L+R)/2+1, R, oL, oR, row));
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    ffi cin >> inp[i][0] >> inp[i][1];
    inp[K][0] = 2*N; K++;
    For (i, 0, N+1) ffj dp[j][i] = INF;
    dp[0][inp[0][0]] = 0;
    For (k, 1, K) {
        build(1, 0, N, k-1);
        int fr = inp[k-1][1] - inp[k-1][0];/// flip range
        int r2 = inp[k][0] - inp[k-1][1];
        //w<< fr s r2<<e;
        For (t, 0, N+1) {
            /// no flips
            int x = t-r2-fr;
            //w<< "for 0:" s x<<e;
            if (x >= 0 && x <= N) dp[k][t] = min(dp[k][t], dp[k-1][x]);
            /// one flip
            int l = inp[k-1][0]-t+r2;
            int r = inp[k-1][0]-t+r2+fr;
            if (l > N || r < 0) {}
            else {
                l = max(l, 0), r = min(r, N);
                dp[k][t] = min(dp[k][t], 1+query(1, 0, N, l, r, k-1));
                //For (i, l, r+1) dp[k][t] = min(dp[k][t], 1+dp[k-1][i]);
            }
            /// two flips
            l = t-r2-fr+1, r = t-r2;
            if (l > N || r < 0) {}
            else {
                l = max(l, 0), r = min(r, N);
                dp[k][t] = min(dp[k][t], 2+query(1, 0, N, l, r, k-1));
                //For (i, l, r+1) dp[k][t] = min(dp[k][t], 2+dp[k-1][i]);
            }
            //w<< k s t s dp[k][t]<<e;
        }
    }

    if (dp[K-1][N] == INF) w<< "Hungry"<<e;
	else w<< "Full"<<e<<dp[K-1][N]<<e;
}
