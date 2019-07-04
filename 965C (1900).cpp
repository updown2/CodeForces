#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
#define a first
#define b second
#define mp make_pair
#define eb emplace_back
#define w cout
#define e endl
#define s <<" "<<
#define int long long
#define c <<" : "<<

const int MAXN = 5000, MOD = 1000000007;

int N, K, M, D, out;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> M >> D;
    For (i, 1, D+1) {
        int sp = K*(i-1)+1;
        //w<< i c sp<<e;
        out = max(out, i*min(M, N/sp));
        if (sp > N) break;
    }
    w<< out<<e;
}
