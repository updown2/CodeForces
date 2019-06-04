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
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 15, INF = 1000000000000000000;
//Global Variables
int T, N, M, K, dist[MAXN][MAXN], out, save;
bool got[MAXN], imp[MAXN], vis[MAXN];
priority_queue<pair<int, int> > n1; /// (-dist, node)

main() {
    //ifstream cin ("test.in");
    //ifstream cin(".in"); ofstream cout(".out");
    ios_base::sync_with_stdio; cin.tie(0);
    cin >> T;
    For (t, 0, T) {
        cin >> N >> M >> K;
        out = INF;
        ffa dist[i][j] = INF;
        ffi got[i] = false;
        For (i, 0, M) {int a, b, d; cin >> a >> b >> d; a--; b--; dist[a][b] = dist[b][a] = min(dist[a][b], d);}
        For (i, 0, K) {int a; cin >> a; got[a-1] = true;}
        For (k, 0, N) ffa dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        /// try all possibilities
        For (x, 0, 1<<N) {
            bool good = true;
            ffi if (got[i] && !(x & 1<<i)) good = false;
            if (!good) continue;
            ffi {
                if (x & 1<<i) imp[i] = true;
                else imp[i] = false;
            }
            ffi vis[i] = false;
            save = 0;
            ffi if (imp[i]) {n1.push(mp(0, i)); break;}
            while (!n1.empty()) {
                int d = -n1.top().a, at = n1.top().b; n1.pop();
                if (vis[at]) continue;
                save += d;
                vis[at] = true;
                ffi if (imp[i] && !vis[i]) n1.push(mp(-dist[at][i], i));
            }
            out = min(out, save);
        }
        w<< out<<e;
    }
}
