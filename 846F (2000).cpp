#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, MAXN)
#define a first
#define b second
#define mp make_pair
#define eb emplace_back
#define w cout
#define e endl
#define s <<" "<<
#define int long long
#define c <<" : "<<

const int MAXN = 1000001, MOD = 998244353;

int N, out, p[MAXN];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; ffj p[j] = -1;
    ffi {
        int a; cin >> a;
        out += (i-p[a])*(N-i);
        p[a] = i;
        //w<< i c out<<e;
    }
    out -= N; out *= 2; out += N;
    w<< fixed<< setprecision(6)<< out/(double)(N*N)<<e;
}
