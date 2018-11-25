#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 201, INF = 100000000000000;
//Global Variables
int N, K, X, a[MAXN], dp[MAXN][MAXN][MAXN];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> X; ffi cin >> a[i];
    For (i, 0, N+1) For (j, 0, X+1) For (k, 0, N+1) dp[i][j][j] = -INF;
    dp[0][0][0] = 0;
    ffi For (j, 0, X+1) {
        /// take pic
        if (j != 0) {
            int big = -INF;
            For (k, 0, K) big = max(big, dp[i-1][j-1][k]);
            dp[i][j][0] = a[i] + big;
            //w<< i s j c dp[i][j][0]<<e;
        }
        For (k, 1, K) dp[i][j][k] = dp[i-1][j][k-1];
    }
    int big = -1;
    For (k, 0, K) big = max(big, dp[N][X][k]);
    w<< big <<e;
}
