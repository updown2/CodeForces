/*
Centroid decomposition:
- Assign the letter x to the centroid
- Recurse on the subtree and assign x+1 to that centroid
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, P)
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
const int MAXN = 100000;
//Global Variables
int N, out[MAXN], siz, und[MAXN];
vector<int> adj[MAXN], nodes;
bool gone[MAXN];

void dfs(int at, int p) {
    if (gone[at]) return;
    siz++;
    nodes.pb(at);
    und[at] = 1;
    for (int i: adj[at]) if (i != p && !gone[i]) {
        dfs(i, at);
        und[at] += und[i];
    }
}

int fc(int at) {
    siz = 0;
    nodes.clear();
    dfs(at, -1);
    //w<< "dfs done"<<e;
    int sm = siz, val = -1;
    for (int i: nodes) {
        //w<< "node" s i+1 s und[i] c siz<<e;
        int curr = siz-und[i];
        for (int j: adj[i]) if (!gone[j] && und[j] < und[i]) curr = max(curr, und[j]);
        if (curr < sm) {
            sm = curr;
            val = i;
        }
    }
    return val;
}
void solve(int cen, int val) {
    //w<< "solve:" s cen+1<<e;
    if (val == 26) {w<< "Impossible!"<<e; exit(0);}
    cen = fc(cen); /// have the centroid now
    //w<< "centroid is" s cen+1<<e;
    out[cen] = val;
    gone[cen] = true;
    for (int i: adj[cen]) if (!gone[i]) solve(i, val+1);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    For (i, 1, N) {int a, b; cin >> a >> b; a--; b--; adj[a].pb(b); adj[b].pb(a);}
    solve(0, 0);
    ffi w<< (char)(out[i]+'A')<< " "; w<<e;
}
