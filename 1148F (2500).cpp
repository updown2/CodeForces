#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(unsigned long long i=a; i<b; i++)
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
//#define c <<" : "<<e;

const int MAXN = 300000;

int N, val[MAXN], tot1;
unsigned long long msk[MAXN], out, p2[63];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; ffi {cin >> val[i] >> msk[i]; tot1 += val[i];}
    p2[0] = 1; For (i, 1, 63) p2[i] = 2*p2[i-1];
    tot1 /= abs(tot1);
    For (k, 0, 62) {
        //w<<(k+1) s p2[k+1]<<e;
        int tot2 = 0;
        ffi if (p2[k] <= msk[i] && msk[i] < p2[k+1]) tot2 += val[i];
        if (tot2 != 0) tot2 /= abs(tot2);
        //w<< tot1 s tot2<<e;
        if (tot1*tot2 > 0) {
            /// make the flip
            out += p2[k];
            //w<< "flip" s k<<e;
            ffi if (msk[i] & p2[k]) val[i] *= -1;
        }
    }
    w<< out<<e;
}
