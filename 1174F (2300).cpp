#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define a first
#define b second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define w cout
#define e endl
#define s <<" "<<
//#define int long long
#define c <<" : "<<

const int MAXN = 200000;

int N, dep[MAXN], dx, siz[MAXN], big, par[MAXN];
vector<int> adj[MAXN], curr;
bool done[MAXN];

void go(int at, int p) {
    if (at != 0) dep[at] = dep[p]+1;
    par[at] = p;
    for (int i: adj[at]) if (i != p) go(i, at);
}
void ttry(int at, int p) {
    curr.pb(at); big++; siz[at] = 1;
    for (int i: adj[at]) if (!done[i] && i != p) {
        ttry(i, at);
        siz[at] += siz[i];
    }
}
void del(int at) {
    if (done[at]) return;
    done[at] = true;
    for (int i: adj[at]) if (i != par[at]) del(i);
}
void solve(int at) {
    //w<< "looking at" s at+1<<e;
    curr.clear();
    big = 0; ttry(at, at);
    for (int i: curr) {
        //w<< i+1 s siz[i]<<e;
        bool good = true;
        if (big-siz[i] > big/2) good = false;
        for (int j: adj[i]) if (!done[j] && par[i] != j) {
            if (siz[j] > big/2) good = false;
        }
        if (good) at = i;
    }
    /// at is now the centroid
    int dist; w<< 'd' s at+1<<e; cin >> dist;
    if (dist == 0) {
        /// got the answer
        w<< '!' s at+1<<e;
        exit(0);
    }
    if (dist + dep[at] == dx) {
        /// it's a child
        done[at] = true;
        w<< 's' s at+1<<e;
        cin >> at; at--;
        if (at < 0) exit(0);
        solve(at);
    }
    else {
        /// not a child so delete the subtree
        del(at);
        assert(at != 0);
        for (int i: curr) if (!done[i]) {
            solve(i);
            break;
        }
    }
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    For (i, 1, N) {int a, b; cin >> a >> b; a--; b--; adj[a].pb(b); adj[b].pb(a);}
    go(0, 0);
    w<< 'd' s 1<<e; cin >> dx;
    solve(0);
}
