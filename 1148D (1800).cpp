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

int N, inp[MAXN][2];
vector<pair<pair<int, int>, int> > up, down;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi {
        int a, b; cin >> a >> b;
        if (a < b) up.eb(mp(a, b), i);
        else down.eb(mp(b, a), i);
    }
    if (up.size() > down.size()) {
        sort(up.begin(), up.end());
        reverse(up.begin(), up.end());
        w<< up.size()<<e;
        for (auto i: up) w<< i.b+1<< " "; w<<e;
    }
    else {
        sort(down.begin(), down.end());
        w<< down.size()<<e;
        for (auto i: down) w<< i.b+1<< " "; w<<e;
    }
}
