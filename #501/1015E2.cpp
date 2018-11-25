#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 1, M+1)
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
//500,000,000 operations
const int MAXN = 1002, INF = 10000000000;
//Global Variables
int N, M, l, r, u, d;
bool a[MAXN][MAXN], cov[MAXN][MAXN];
vector<pair<pair<int, int>, int> > out;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffa {char b; cin >> b; a[i][j] = (b=='*');}
    ffa if (a[i][j]) {
        l = r = u = d = 0;
        while (a[i-l-1][j]) l++;
        while (a[i+r+1][j]) r++;
        while (a[i][j+u+1]) u++;
        while (a[i][j-d-1]) d++;
        int x = min(min(l, r), min(u, d));
        if (x == 0) continue;
        cov[i][j] = true;
        For (k, 1, x+1) cov[i][j+k] = cov[i][j-k] = cov[i-k][j] = cov[i+k][j] = true;
        out.pb(mp(mp(i, j), x));
    }
    bool good = true;
    ffa if (a[i][j] && !cov[i][j]) good = false;
    if (!good) {w<<-1<<e; return 0;}
    w<< out.size()<<e;
    for (auto i: out) {
        w<< i.a.a s i.a.b s i.b <<e;
    }
}
