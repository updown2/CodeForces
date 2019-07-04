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

const int MAXN = 1000000;
int N, lx, ly, big, out;
string in;
map<pair<int, int>, int> vis;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> in;
    vis[mp(0, 0)] = 0;
    big = -1;
    ffi {
        if (in[i] == 'R') lx++;
        if (in[i] == 'L') lx--;
        if (in[i] == 'D') ly++;
        if (in[i] == 'U') ly--;
        if (vis.find(mp(lx, ly)) != vis.end()) big = max(big, vis[mp(lx, ly)]);
        out = max(out, i-big);
        vis[mp(lx, ly)] = i+1;
    }
    w<< out<<e;
}
