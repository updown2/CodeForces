#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN = 100000;
///500,000,000
int X, D, p2[30], at=1;
vector<int> out;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> X >> D;
    p2[0] = 1; For (i, 1, 30) p2[i] = 2*p2[i-1];
    for (int i=29; i>=1; i--) {
        int x = p2[i]-1;
        while (X >= x) {
            For (j, 0, i) out.pb(at);
            at += D+1;
            X -= x;
        }
    }
    w<< out.size()<<e;
    for (int i: out) w<< i<< " "; w<<e;
}
