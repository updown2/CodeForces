#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffj ffi
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
const int MAXN = 100001, INF = 10000000000;
//Global Variables
int N, M, inp[10][MAXN], loc[10][MAXN], far[10][MAXN];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffa {cin >> inp[j][i]; loc[j][inp[j][i]] = i;}
    ffi far[0][i] = N-1;
    For (j, 1, M) {
        far[j][N-1] = N-1;
        for (int i=N-2; i>=0; i--) {
            int x = loc[j-1][inp[j][i]]; /// loc in prev row
            if (far[j-1][x] == x) far[j][i] = i;
            else if (inp[j-1][x+1] == inp[j][i+1]) far[j][i] = far[j][i+1];
            else far[j][i] = i;
        }
        //ffi w<< far[j][i]<< " "; w<<e;
    }
    int out = 0;
    ffi out += far[M-1][i] - i+1;
    w<< out<<e;
}
