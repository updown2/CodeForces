#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=100, INF=1000000000000000000;
///500,000,000
string a, b;
int N, out;
bool g[2][MAXN];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b; N = a.length();
    ffi {
        if (a[i] == '0') g[0][i] = true;
        else g[0][i] = false;
        if (b[i] == '0') g[1][i] = true;
        else g[1][i] = false;
    }
    ffi if (g[0][i] && g[1][i]) {
        if (i != 0) {
            /// take one from previous col
            if (g[0][i-1]) {
                out++;
                g[0][i-1] = g[0][i] = g[1][i] = false;
                continue;
            }
            if (g[1][i-1]) {
                out++;
                g[1][i-1] = g[0][i] = g[1][i] = false;
                continue;
            }
        }
        if (i != -1) {
            /// take one from next col
            if (g[0][i+1]) {
                out++;
                g[0][i+1] = g[0][i] = g[1][i] = false;
                continue;
            }
            if (g[1][i+1]) {
                out++;
                g[1][i+1] = g[0][i] = g[1][i] = false;
                continue;
            }
        }
    }
    w<< out<<e;
}