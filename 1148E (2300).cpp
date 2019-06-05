#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define a first
#define b second
#define mp make_pair
#define eb emplace_back
#define w cout
#define e endl
#define s <<" "<<
#define int long long
//#define c <<" : "<<e;

const int MAXN = 300000;

int N, inp2[MAXN];
pair<int, int> inp1[MAXN];
vector<pair<pair<int, int>, int> > ans;
stack<pair<int, int> > lef; /// (+ value, index)


main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; ffi {cin >> inp1[i].a; inp1[i].b = i;} ffi cin >> inp2[i];
    sort(inp1, inp1+N); sort(inp2, inp2+N);
    ffi inp1[i].a = inp2[i] - inp1[i].a;
    ffi {
        if (inp1[i].a == 0) continue; /// don't move it
        if (inp1[i].a > 0) {
            lef.push(inp1[i]);
        }
        else {
            while (inp1[i].a < 0 && lef.size() > 0) {
                pair<int, int> x = lef.top(); lef.pop();
                int d = min(x.a, -inp1[i].a);
                inp1[i].a += d; x.a -= d;
                ans.eb(mp(x.b, inp1[i].b), d);
                if (x.a != 0) lef.push(x);
            }
            if (inp1[i].a != 0) {w<<"NO"<<e; return 0;}
        }
    }
    if (lef.empty()) {
        w<< "YES"<<e<<ans.size()<<e;
        for(auto i: ans) w<< i.a.a+1 s i.a.b+1 s i.b<<e;
    }
    else w<< "NO"<<e;
}
