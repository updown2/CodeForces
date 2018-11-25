#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 1, N+1)
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
const int MAXN = 2002, INF = 10000000000;
//Global Variables
int N, K, cnt[MAXN][MAXN];
char grid[MAXN][MAXN];
bool curr[MAXN][MAXN];
string out;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    ffa cin >> grid[i][j];
    ffi cnt[i][0] = cnt[0][i] = -1;
    cnt[0][1] = cnt[1][0] = K;
    ffa {
        if (grid[i][j] == 'a') cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]);
        else cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1])-1;
    }
    curr[1][1] = true;
    For (i, 2, 2*N+1) {
        /// check for cnt[x][y] >= 0
        bool have = false;
        For (y, 1, i) {int x = i-y; if (x > N || y > N || !curr[x][y]) continue;
            //w<< i c x s y<<e;
            if (cnt[x][y] >= 0) have = true;
        }
        if (have) {
            out += 'a';
            For (y, 1, i) {int x = i-y; if (x > N || y > N || !curr[x][y]) continue;
                //w<< i c x s y<<e;
                if (cnt[x][y] >= 0) curr[x+1][y] = curr[x][y+1] = true;
            }
            continue;
        }
        /// find the smallest
        char best = 'z';
        For (y, 1, i) {int x = i-y; if (x > N || y > N || !curr[x][y]) continue;
            //w<< i c x s y<<e;
            if (grid[x][y] < best) best = grid[x][y];
        }
        out += best;
        For (y, 1, i) {int x = i-y; if (x > N || y > N || !curr[x][y]) continue;
            //w<< i c x s y<<e;
            if (grid[x][y] <= best) curr[x+1][y] = curr[x][y+1] = true;
        }

    }
    w<< out<<e;
}
