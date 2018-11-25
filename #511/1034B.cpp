#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 201, INF = 100000000000000;
//Global Variables
int N, M;

void ans(int x) {w<< x<<e; exit(0);}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    if (N > M) swap(N, M);
    if (N == 1) {
        if (M%6 <= 3) ans(6*(M/6));
        if (M%6 == 4) ans(6*(M/6) + 2);
    }
    if (N == 2) {
        if (M == 2) ans(0);
        if (M == 3 || M == 7) ans(N*M-2);
    }
    if (N%2 == 1 && M%2 == 1) ans(N*M-1);
    ans(N*M);
}
