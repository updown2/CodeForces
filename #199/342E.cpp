#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
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
#define double long double
//500,000,000 operations
const int MAXN = 100000, INF = 1000000000000000000;
//Global Variables
int N, M, bucket = 400, d[MAXN], anc[MAXN][20], dep[MAXN];
bool red[MAXN], vis[MAXN];
vector<int> adj[MAXN];
vector<int> add;
queue<int> next1;

void go (int at, int de, int par) {
    dep[at] = de;
    anc[at][0] = par;
    for (int i: adj[at]) if (i != par) go(i, de+1, at);
}
int LCA (int A, int B) {
    if (dep[A] < dep[B]) swap(A, B);
    int x = dep[A] - dep[B];
    For (k, 0, 20) if (x & (1<<k)) A = anc[A][k];
    if (A == B) return A;
    for (int k=19; k>=0; k--) if (anc[A][k] != anc[B][k]) A = anc[A][k], B = anc[B][k];
    return anc[A][0];
}
int dist(int A, int B) {return dep[A] + dep[B] - 2*dep[LCA(A, B)];}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    For (i, 1, N) {int a, b; cin >> a >> b; a--; b--; adj[a].pb(b); adj[b].pb(a);}
    go(0, 0, 0);
    //ffi w<< i+1 c dep[i]<<e;
    For (k, 0, 19) ffi anc[i][k+1] = anc[anc[i][k]][k];
    red[0] = true;
    For (i, 0, M) {
        if (i%bucket == 0) {
            /// reset, new bucket
            for (int j: add) red[j] = true;
            add.clear();
            ffj {
                d[j] = INF;
                vis[j] = false;
                if (red[j]) {vis[j] = true; d[j]=0; next1.push(j);}
            }
            while (!next1.empty()) {
                int at = next1.front(); next1.pop();
                for (int k: adj[at]) if (!vis[k]) {
                    vis[k] = true;
                    d[k] = d[at]+1;
                    next1.push(k);
                }
            }
        }
        int t, v; cin >> t >> v; v--;
        if (t == 1) add.pb(v);
        else {
            int sm = d[v];
            for (int j: add) sm = min(sm, dist(v, j));
            w<< sm<<e;
        }
    }
}
