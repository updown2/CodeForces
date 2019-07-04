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

int N, p;
pair<int, int> vals[MAXN];
vector<pair<int, int> > lef;
bool taken[MAXN];
vector<int> ans;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; N /= 2;
    ffi {int a, b; cin >> a >> b; vals[i] = mp(min(a, b), max(a, b));}
    sort(vals, vals+N);
    ffi {
        if (vals[i].a >= p) {
            ans.pb(vals[i].a); ans.pb(vals[i].b);
            p = vals[i].b;
        }
        else lef.eb(vals[i].b, vals[i].a);
    }
    sort(lef.begin(), lef.end()); reverse(lef.begin(), lef.end());
    p = 1000000000;
    for (auto i: lef) {
        if (i.a > p) {w<<-1<<e; exit(0);}
        ans.pb(i.a); ans.pb(i.b); p = i.b;
    }
    for (int i: ans) w<< i << " ";
    w<<e;
}
