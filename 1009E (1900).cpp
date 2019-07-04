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

const int MAXN = 1000000, MOD = 998244353;

int N, A[MAXN], out, p2 = 1;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; ffi cin >> A[N-i-1];
    out += A[0];
    For(i, 1, N) {
        out += A[i]* (p2*(i+2)%MOD); out %= MOD;
        p2 *= 2; p2 %= MOD;
    }
    w<< out<<e;
}
