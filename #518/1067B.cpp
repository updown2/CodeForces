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
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=100000, INF=1000000000;
///500,000,000
int N, K, dist[MAXN], big;
bool vis[MAXN];
vector<int> adj[MAXN];
queue<pair<int, int> > next1;

void fail() {
    w<< "No"<<e;
    exit(0);
}

void go(int at) {
    if (vis[at]) return;
    vis[at] = true;
    if (dist[at] == 0) return;
    if (dist[at] == K) {
        big++;
        if (adj[at].size() < 3) fail();
        for (int i: adj[at]) if (dist[i] != K-1) fail();
    }
    else {
        if (adj[at].size() < 4) fail();
        int bad = 0;
        for (int i: adj[at]) if (dist[i] != dist[at]-1) bad++;
        if (bad != 1) fail();
    }
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    if (N <= 3) fail();
    For (i, 1, N) {int a, b; cin >> a >> b; a--; b--; adj[a].pb(b); adj[b].pb(a);}
    ffi if (adj[i].size() == 1) {next1.push(mp(i, 0));}
    while (!next1.empty()) {
        int at = next1.front().a; int d = next1.front().b; next1.pop();
        if (vis[at]) continue;
        vis[at] = true;
        dist[at] = d;
        for (int i: adj[at]) next1.push(mp(i, d+1));
    }
    ffi vis[i] = false;
    //ffi w<< i+1 c dist[i]<< e;
    ffi go(i);
    if (big != 1) fail();
    w<< "Yes"<<e;
}
