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
const int MAXN = 100, INF = 10000000000;
//Global Variables
int N, A[MAXN], tot, sm;

int calc(int K) {
    int ret = 0;
    ffi ret += K-A[i];
    return ret;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; ffi {cin >> A[i]; tot += A[i]; sm = max(sm, A[i]);}
    int a = sm, b = INF;
    while (a != b) {
        int mid = (a+b)/2;
        if (calc(mid) > tot) b = mid;
        else a = mid+1;
    }
    w<< a<<e;
}
