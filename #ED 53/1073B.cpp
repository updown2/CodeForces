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
//#define int ll
//500,000,000 operations
const int MAXN = 200001, INF = 1000000000;
//Global Variables
int N, inp[MAXN], loc[MAXN], at;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi {cin >> inp[i]; loc[inp[i]] = i;}
    at = 0;
    ffi {
        int a; cin >> a;
        if (loc[a] < at) {w<< 0<< " "; continue;}
        w << loc[a]-at+1 << " ";
        at = loc[a]+1;
    }
    w<<e;
}
