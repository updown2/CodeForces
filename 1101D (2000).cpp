/*
centroid decomposition:
- Find the prime factors for every path starting at the centroid
- Store path[prime factor] = maximum length where the gcd is a multiple of the prime factor
- For each subtree, for the max length for each gcd loop through all multiples
that already are in the array to get the max length
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
//#define int ll
//500,000,000 operations
const int MAXN = 200001;
//Global Variables
int N, inp[MAXN], out, siz, und[MAXN], path[6];
vector<int> adj[MAXN], nodes, fac;
bool gone[MAXN], prime[MAXN];

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

int gcd(int a, int b) {return a==0 ? b:gcd(b%a, a);}
void dfsans(int at, int ggg, int p, int len) {
    if (gone[at]) return;
    ggg = gcd(ggg, inp[at]);
    bool prog = false;
    For (i, 0, fac.size()) {
        int x = fac[i];
        if (ggg%x == 0) {
            out = max(out, path[i]+len-1);
            prog = true;
        }
    }
    if (!prog) return;
    for (int i: adj[at]) if (i != p) dfsans(i, ggg, at, len+1);
}
void dfsupd(int at, int ggg, int p, int len) {
    if (gone[at]) return;
    ggg = gcd(ggg, inp[at]);
    bool prog = false;
    For (i, 0, fac.size()) {
        int x = fac[i];
        if (ggg%x == 0) {
            path[i] = max(path[i], len);
            out = max(out, len);
            //w<< fac[i] s path[i]<<e;
            prog = true;
        }
    }
    if (!prog) return;
    for (int i: adj[at]) if (i != p) dfsupd(i, ggg, at, len+1);
}
void solve(int cen) {
    //w<< "solve:" s cen+1<<e;
    cen = fc(cen); /// have the centroid now
    //w<< "centroid is" s cen+1<<e;
    /// solve paths crossing the centroid
    if (inp[cen] != 1) {
        fac.clear();
        For (i, 1, sqrt(inp[cen])+1) if (inp[cen]%i == 0) {
            /// factors are i and inp[cen]/i
            if (prime[i]) {
                bool good = true;
                for (int j: fac) if (j == i) good = false;
                if (good) fac.pb(i);
            }
            if (prime[inp[cen]/i]) {
                bool good = true;
                for (int j: fac) if (j == inp[cen]/i) good = false;
                if (good) fac.pb(inp[cen]/i);
            }
        }
        //for (int i: primes) if (inp[cen]%i == 0) fac.pb(i); /// max of 6 factors
        //w<< inp[cen] << ":"; for (int i: fac) w s i; w<<e;
        For (i, 0, fac.size()) path[i] = 1;
        out = max(out, (int)1);
        for (int i: adj[cen]) if (!gone[i]) {
            dfsans(i, inp[cen], cen, 2);
            dfsupd(i, inp[cen], cen, 2);
        }
    }
    /// end solve paths crossing the centroid
    gone[cen] = true;
    for (int i: adj[cen]) if (!gone[i]) solve(i);
}

void del(int x) {for (int i=x+x; i<MAXN; i+=x) prime[i] = false;}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    For (i, 2, MAXN) prime[i] = true;
    For (i, 2, MAXN) del(i);
    //for (int i: primes) w<< i<<e;
    cin >> N;
    ffi cin >> inp[i];
    For (i, 1, N) {int a, b; cin >> a >> b; a--; b--; adj[a].pb(b); adj[b].pb(a);}
    solve(0);
    w<< out<<e;
}
