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

int T, N;
string a, b;

main() {
    ifstream cin("hamming.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    For (t, 0, T) {
        cin >> N >> a >> b;
        sort(a.begin(), a.end()); sort(b.begin(), b.end()); reverse(b.begin(), b.end());
        int out = 0;
        ffi if (a[i] != b[i]) out++;
        w<< out<<e;
    }
}
