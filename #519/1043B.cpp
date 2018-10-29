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
const int MAXN = 1001, INF = 10000000000;
//Global Variables
int N, A[MAXN], X[MAXN];
set<int> ans;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; N++; For (i, 1, N) cin >> A[i];
    For (K, 1, N) {
        /// first K
        For (i, 1, K+1) X[i-1] = A[i]-A[i-1];
        /// check if rest work
        bool good = true;
        For (i, K+1, N) if (A[i] != X[(i-1)%K] + A[i-1]) good = false;
        if (good) ans.insert(K);
    }
    w<< ans.size()<<e;
    for (int i: ans) w<< i<< " "; w<<e;
}
