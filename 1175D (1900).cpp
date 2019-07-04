#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define a first
#define b second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define w cout
#define e endl
#define s <<" "<<
#define int long long
#define c <<" : "<<

const int MAXN = 300000;

int N, K, vals[MAXN], suf[MAXN], out;


main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K; ffi cin >> vals[i];
    suf[N-1] = vals[N-1];
    for (int i=N-2; i>=0; i--) suf[i] = suf[i+1] + vals[i];
    out = suf[0];
    ffi suf[i] *= -1;
    sort(suf+1, suf+N);
    //ffi w<< suf[i]<<e;
    For (i, 1, K) out -= suf[i];
    w<< out<<e;
}
