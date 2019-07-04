#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=200000, INF = 1000000000;

int T, N=12, vals[12];

main() {
    ifstream cin("hello.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    For (t, 0, T) {
        ffi cin >> vals[i];
        string out = "yes";
        if (vals[1] < vals[0] || vals[2] < vals[1] || vals[3] < vals[2]) out = "no";
        For (i, 4, N) if (vals[i] < vals[3]) out = "no";
        w<< out<<e;
    }
}
