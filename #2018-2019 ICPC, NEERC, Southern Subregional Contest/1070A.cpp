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
//#define int ll
//500,000,000 operations
const int MAXN = 250000;
//Global Variables
int D, S;
bool vis[501][5001];
queue<pair<string, pair<int, int> > > next1; /// (number, (remainder, sum))

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> D >> S;
    next1.push(mp("", mp(0, 0)));
    vis[0][0] = true;
    while (!next1.empty()) {
        string curr = next1.front().a; int r = next1.front().b.a, sum = next1.front().b.b;
        next1.pop();
        if (r == 0 && sum == S) {
            w<< curr<<e;
            return 0;
        }
        //w<< r s sum<<e;
        For (i, 0, 10) if (sum+i <= S && !vis[(r*10+i)%D][sum+i]) { /// next digit
            vis[(r*10+i)%D][sum+i] = true;
            next1.push(mp(curr + (char)('0'+i), mp((r*10+i)%D, sum+i)));
        }
    }
    w<< -1<<e;
}
