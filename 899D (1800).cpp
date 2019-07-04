#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define a first
#define b second
#define mp make_pair
#define eb emplace_back
#define w cout
#define e endl
#define s <<" "<<
#define int long long
#define c <<" : "<<

const int MAXN = 1001, MOD = 1000000007;

int N, out, base, digits;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    /// there are 0 9's
    if (N < 5) {w<< N*(N-1)/2<<e; return 0;}
    int big = 2*N;
    int cop = big;
    while (cop > 0) {
        digits++;
        cop /= 10;
    }
    For (i, 1, digits) {base *= 10; base += 9;}
    //w<<digits s base<<e;
    For (i, 0, 10) {
        /// curr = i9...9(9 repeats base times)
        int curr = i*pow(10, digits-1) + base;
        int mid = (curr+1)/2;
        if (N < mid) continue;
        //w<< curr s mid c (min(N, curr-1) - mid + 1)<<e;
        out += min(N, curr-1) - mid + 1;
    }
    w<< out<<e;
}
