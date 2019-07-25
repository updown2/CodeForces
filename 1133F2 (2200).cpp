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
const int MAXN=200000, INF = 1000000000;

int N, M, D, par[MAXN], comp, ext, edges[MAXN][2];
vector<int> one;
bool used[MAXN];
vector<pair<int, int> > take;

int root(int a) {
    if (par[a] == a) return a;
    par[a] = root(par[a]); return par[a];
}
void comb(int a, int b) {
    a = root(a); b = root(b);
    if (a == b) return;
    par[a] = b; comp--;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> D; comp = N;
    ffi par[i] = i;
    ffj {
        int a, b; cin >> a >> b; a--; b--;
        if (a > b) swap(a, b);
        if (a == 0) one.pb(b);
        else comb(a, b);
        edges[j][0] = a; edges[j][1] = b;
    }
    if (comp-1 > D || one.size() < D) {w<< "NO"<<e; return 0;}
    w<< "YES"<<e;
    ext = D-comp+1;
    //w<< ext<<e;
    for (int i: one) {
        int r = root(i);
        if (used[r]) {
            if (ext > 0) {take.eb(0, i); ext--; comb(0, i);}
        }
        else {
            take.eb(0, i);
            used[r] = true;
            comb(0, i);
        }
    }
    ffi par[i] = i;
    for (auto i: take) {
        w << i.a+1 s i.b+1<<e;
        comb(i.a, i.b);
    }
    ffj {
        int a = edges[j][0], b = edges[j][1];
        if (a == 0) continue;
        int x = root(a), y = root(b);
        if (x != y) {
            w<< a+1 s b+1<<e;
            comb(x, y);
        }
    }
}
