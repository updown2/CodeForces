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
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=200000, INF = 1000000000;

int N, dp1[MAXN], dp2[MAXN], siz[MAXN];
/// dp1[i] = if the start was at or above i, how much does subtree of i contribute
/// dp2[i] if start is in subtree i, how much does subtree of i contribute
/// a node contributes when it becomes black
vector<int> adj[MAXN];

void go(int at, int p) {
    siz[at] = 1;
    int diff = -INF;
    for (int i: adj[at]) if (i != p) {
        go(i, at);
        siz[at] += siz[i];
        dp1[at] += dp1[i];
        diff = max(diff, dp2[i]-dp1[i]+N-siz[i]);
    }
    if (siz[at] == 1) dp2[at] = N;
    else dp2[at] = dp1[at] + diff;
    dp1[at] += siz[at];
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    For (i, 1, N) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }
    go(0, 0);
    //ffi w<< i+1 c dp1[i] s dp2[i]<<e;
    w<< max(dp1[0], dp2[0])<<e;
}
