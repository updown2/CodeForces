#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define s <<" "<<
 #define w cout
#define e "\n"
#define mp make_pair
#define a first
#define b second
#define pb push_back
#define int ll
const int MAXN=51, INF=10000000000;
///500,000,000
int N, tot, dp[MAXN][1001], par[MAXN], val[MAXN], W[MAXN], out;
vector<int> adj[MAXN];

void dfs(int at) {
    dp[at][val[at]] = W[at];
    for (int i: adj[at]) dfs(i);
    int p = par[at], vp = val[par[at]], wp = W[par[at]];
    //w<< at s ":"<<e; For (i, 0, 8) w<< i s ":" s dp[at][i]<<e;
    if (at != 0) for (int j=1000; j>=0; j--) For (i, 0, 1001) if (j>=i) {
        dp[p][j] = min(dp[p][j], dp[at][i]+dp[p][j-i]);
    }
    //w<< "par" s p s ":"<<e; For (i, 0, 8) w<< i s ":" s dp[p][i]<<e;
}

main() {
	//ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> tot;
	N++;
	For (i, 1, N) {
        cin >> W[i] >> val[i] >> par[i];
        adj[par[i]].pb(i);
	}
	ffi For (j, 0, 1001) dp[i][j] = INF;
	dfs(0);
	For (i, 1, 1001) if (dp[0][i] <= tot) out = i;
	w<<out<<e;
}
