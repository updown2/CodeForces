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

int N, sm = 10, hv = 10;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi {int a; cin >> a; sm = min(sm, a);}
    For(i, 0, 10) {int a; cin >> a; hv = min(hv, a);}
    if (sm < hv) w<< sm<<e;
    else w<< 10<<e;
}
