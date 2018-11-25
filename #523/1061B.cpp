#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K+1)
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
const int MAXN = 100000, INF = 10000000000;
//Global Variables
int N, M, inp[MAXN], out;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffi {cin >> inp[i]; inp[i] *= -1;}
    sort(inp, inp+N);
    ffi inp[i] *= -1;
    For (i, 1, N) {
        if (inp[i-1] <= inp[i]) {
            int a = max((int)1, inp[i-1]-1);
            out += inp[i]-a;
            inp[i] = a;
        }
    }
    sort(inp, inp+N);
    For (i, 1, N) {
        if (inp[i] == inp[i-1]) out+=inp[i]-1;
        else out += inp[i-1];
    }
    w<< out<<e;
}
