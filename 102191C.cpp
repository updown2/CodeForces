#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define a first
#define b second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define w cout
#define e endl
#define s <<" "<<
#define int long long
#define c <<" : "<<
const int MAXN = 300000;

int N, vals[MAXN];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; ffi cin >> vals[i];
    if (N <= 4) {w<< -1<<e; return 0;}
    if (N%2 == 0) {
        For (i, 0, N/2) w<< vals[i*2]<< " ";
        w<< vals[1];
        for (int i=N-1; i>=3; i-= 2) w s vals[i];
        w<<e;
    }
    else {
        for (int i=0; i<N; i+= 2) w<< vals[i]<< " ";
        for (int i=1; i<N; i+= 2) w<< vals[i]<< " "; w<<e;
    }
}
