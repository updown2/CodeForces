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
const int MAXN = 200000, INF = 10000000000;
//Global Variables
int N, dep[2], siz[MAXN], out;
vector<int> adj[MAXN];

void go(int at, int d, int from) {
    dep[d%2]++;
    siz[at] = 1;
    for (int i: adj[at]) if (i != from) {
        go(i, d+1, at);
        siz[at] += siz[i];
    }
    out += siz[at] * (N-siz[at]);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    For (i, 1, N) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }
    go(0, 0, -1);
    out += dep[0]*dep[1];
    w<< out/2 <<e;
}
