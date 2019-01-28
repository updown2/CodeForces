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
//500,000,000 operations
const int MAXN = 10000001, MOD = 1000000007;
//Global Variables
string a, b;
int N, M, out, zb, c0, c1, mul= 2, inv[MAXN], hsh[MAXN], p[MAXN];

int see(int st, int en) {return (((hsh[en]-hsh[st-1]+MOD)%MOD)*inv[st])%MOD;}
int mI(int x, int y) {
    if (y == 0) return 1;
    int p = mI(x, y/2) % MOD; p = (p * p) % MOD;
    return (y%2 == 0)? p : (x * p) % MOD;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b; M = a.length(); N = b.length(); b = ' '+b;
    p[0] = 1; For (i, 1, N+1) p[i] = (p[i-1]*mul)%MOD, inv[i] = mI(p[i], MOD-2);
    For (i, 1, N+1) hsh[i] = (hsh[i-1]+ (b[i]-'a'+1)*p[i])%MOD;


    if (a[0] == '1') {
        ffj {
            if (a[j] == '0') a[j] = '1';
            else a[j] = '0';
        }
    }
    ffj {if (a[j] == '0') c0++; else c1++;}
    while (a[zb] == '0') zb++;
    For (len0, 1, N) {
        if ((N-len0*c0)%c1 == 0) {
            int len1 = (N-len0*c0)/c1;
            if (len1 < 1) continue;
            //w<< len0 s len1<<e;
            int hsh0 = see(1, len0);
            int hsh1 = see(zb*len0+1, zb*len0+len1);
            if (hsh0 == hsh1) continue;
            int at = 1;
            bool good = true;
            for (char x: a) {
                if (x == '0') {
                    if (see(at, at+len0-1) != hsh0) good = false;
                    at += len0;
                }
                else {
                    if (see(at, at+len1-1) != hsh1) good = false;
                    at += len1;
                }
            }
            if (good) out++;
        }
    }
    w<< out<<e;
}
