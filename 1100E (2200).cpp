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
#define eb emplace_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=100000, INF = 1e9;

int N, M, a, loc[MAXN], edges[MAXN][3];
vector<pair<int, int> > adj[MAXN], bck[MAXN];
vector<int> ord, ans;
bool vis[MAXN], open[MAXN], good;

void go1(int at, int x) {
    if (vis[at]) return;
    //w<< at+1<<e;
    if (open[at]) {
        good = false;
        return;
    }
    open[at] = true;
    for (auto i: adj[at]) {
        if (i.a > x) {
            go1(i.b, x);
        }
        else break;
    }
    open[at] = false;
    vis[at] = true;
}
void go2(int at) {
    if (vis[at]) return;
    vis[at] = true;
    for (auto i: bck[at]) {
        if (i.a > a) {
            go2(i.b);
        }
    }
    loc[at] = ord.size();
    ord.pb(at);
}

bool works(int x) {
    good = true;
    ffi vis[i] = false;
    ffi go1(i, x);
    return good;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffj {
        int a, b, d; cin >> a >> b >> d; a--; b--;
        adj[a].eb(d, b); bck[b].eb(d, a);
        edges[j][0] = a; edges[j][1] = b; edges[j][2] = d;
    }
    ffi {sort(adj[i].begin(), adj[i].end()); reverse(adj[i].begin(), adj[i].end());}
    int b = 1e9;
    while (a != b) {
        int mid = (a+b)/2;
        if (works(mid)) b = mid;
        else a = mid+1;
    }
    /// topologically sort
    ffi vis[i] = false;
    ffi go2(i);
    //for (int i: ord) w<< i+1 << " "; w<<e;
    ffj if (edges[j][2] <= a) {
        int x = edges[j][0], y = edges[j][1];
        if (loc[x] > loc[y]) ans.pb(j+1);
    }
    w<< a s ans.size()<<e;
    for (auto i: ans) w<< i << " "; w<<e;
}
