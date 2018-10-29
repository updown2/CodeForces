#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K+1)
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
int N, x, y, pre[MAXN][2], post[MAXN][2];
string dir;

bool works(int ch) {
    if (ch == N) {
        int dx = x, dy = y;
        if (ch >= abs(dx)+abs(dy) && abs(ch-dx-dy)%2 == 0) return true;
        return false;
    }
    int dx = x-post[ch][0], dy = y-post[ch][1];
    if (ch >= abs(dx)+abs(dy) && abs(ch-dx-dy)%2 == 0) return true;
    For (i, ch, N-1) {
        dx = x-(post[i+1][0] + pre[i-ch][0]), dy = y-(post[i+1][1] + pre[i-ch][1]);
        if (ch >= abs(dx)+abs(dy) && abs(ch-dx-dy)%2 == 0) return true;
    }
    dx = x-(pre[N-ch-1][0]), dy = y-(pre[N-ch-1][1]);
    if (ch >= abs(dx)+abs(dy) && abs(ch-dx-dy)%2 == 0) return true;
    return false;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> dir >> x >> y;
    int atx = 0, aty = 0;
    ffi {
        if (dir[i] == 'U') aty++;
        if (dir[i] == 'D') aty--;
        if (dir[i] == 'L') atx--;
        if (dir[i] == 'R') atx++;
        pre[i][0] = atx, pre[i][1] = aty;
    }
    atx = 0, aty = 0;
    for (int i=N-1; i>=0; i--) {
        if (dir[i] == 'U') aty++;
        if (dir[i] == 'D') aty--;
        if (dir[i] == 'L') atx--;
        if (dir[i] == 'R') atx++;
        post[i][0] = atx, post[i][1] = aty;
    }
    if (pre[N-1][0] == x && pre[N-1][1] == y) {w<< 0<<e; return 0;}
    if (N < abs(x)+abs(y) || abs(N-x-y)%2 == 1) {w<< -1<<e; return 0;}
    int a = 1, b=N;
    while (a != b) {
        int mid = (a+b)/2;
        //w<< mid c works(mid)<<e;
        if (works(mid)) b = mid;
        else a = mid+1;
    }
    w<< a<<e;
}
