#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, C)
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
const int MAXN = 100000, INF = 1000000000;
//Global Variables
int N, C, inp[MAXN], dp[MAXN], sum;
multiset<int> have;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C;
    ffi {cin >> inp[i]; sum += inp[i];}
    ffj have.insert(inp[j]);
    dp[C-1] = *(have.begin());
    For (i, C, N) {
        have.insert(inp[i]);
        have.erase(have.find(inp[i-C]));
        dp[i] = max(dp[i-1], dp[i-C] + *(have.begin()));
    }
    w<< sum - dp[N-1]<<e;
}
