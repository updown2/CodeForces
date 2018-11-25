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
const int MAXN=1000000, INF=1000000000, MOD = 1000000007;
///500,000,000
int N, a[MAXN], cnt[MAXN+1], out;
vector<int> divisors[MAXN+1];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=MAXN; i>=1; i--) {
        for (int j=i; j<=MAXN; j+= i) divisors[j].pb(i);
    }
    cnt[0] = 1;
    cin >> N;
    ffi cin >> a[i];
    ffi {
        for (int j: divisors[a[i]]) {
            cnt[j] += cnt[j-1];
            cnt[j] %= MOD;
        }
    }
    For (i, 1, N+1) {
        out += cnt[i];
        out %= MOD;
    }
    w<< out<<e;
}
