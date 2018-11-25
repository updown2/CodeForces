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
const int MAXN = 100, INF = 10000000000;
//Global Variables
int N, M, LR = -1, UD = -1, dist[MAXN][MAXN];
char grid[MAXN][MAXN];
queue<pair<int, int> > next1;

void add (int x, int y, int d) {
    if (x < 0 || x >= N || y < 0 || y >=M || dist[x][y] != -2) return;
    dist[x][y] = d+1;
    next1.push(mp(x, y));
}
bool n (int x, int y, int d) {
    if (x < 0 || x >= N || y < 0 || y >=M) return false;
    return d == 1+dist[x][y];
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffa {
        cin >> grid[i][j];
        if (grid[i][j] == 'F') {next1.push(mp(i, j)); dist[i][j] = 0;}
        else if (grid[i][j] == '*') dist[i][j] = -10;
        else dist[i][j] = -2;
    }
    while (!next1.empty()) {
        int x = next1.front().a; int y = next1.front().b; next1.pop();
        if (x == 0 && y == 0) break;
        add(x-1, y, dist[x][y]); add(x+1, y, dist[x][y]); add(x, y-1, dist[x][y]); add(x, y+1, dist[x][y]);
    }
    //ffi {ffj w<<dist[i][j] << " "; w<<e;}
    int x = 0, y = 0;
    while (grid[x][y] != 'F') {
        int d = dist[x][y];
        if (LR == -1 && (n(x, y-1, d) || n(x, y+1, d)) ) {
            /// the next spot is to the right
            w<< 'R'<<e;
            int nx, ny; cin >> nx >> ny; nx--; ny--;
            if (nx == x && ny == y) LR = 1;
            else {LR = 0; x = nx; y = ny;}
        }
        else if (UD == -1 && (n(x-1, y, d) || n(x+1, y, d)) ) {
            /// the next spot is down
            w<< 'D'<<e;
            int nx, ny; cin >> nx >> ny; nx--; ny--;
            if (nx == x && ny == y) UD = 1;
            else {UD = 0; x = nx; y = ny;}
        }
        else {
            if (n(x, y-1, d)) {
                if (LR == 0) w<<'L'<<e;
                else w<< 'R'<<e;
            }
            else if (n(x, y+1, d)) {
                if (LR == 0) w<<'R'<<e;
                else w<< 'L'<<e;
            }
            else if (n(x-1, y, d)) {
                if (UD == 0) w<<'U'<<e;
                else w<< 'D'<<e;
            }
            else {
                if (UD == 0) w<<'D'<<e;
                else w<< 'U'<<e;
            }
            cin >> x >> y; x--; y--;
        }
    }
}
