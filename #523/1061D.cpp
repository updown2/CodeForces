#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
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
const int MAXN=100000, MOD = 1000000007;
///500,000,000
int N, X, Y, out;
pair<int, int> inp[MAXN];
multiset<int> et;
multiset<int>::iterator it;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> X >> Y;
    ffi cin >> inp[i].a >> inp[i].b;
    sort(inp, inp+N);
    ffi {
//w<< "looking at" s inp[i].a<<e;
        bool done = false;
        if (!et.empty()) {
            it = et.upper_bound(inp[i].a);
            if (it != et.begin()) {
                it--;
                int st = *(it);
                et.erase(it);
                if (Y*(inp[i].a-st+1) <= X) {
                    out += Y*(inp[i].b - st+1);
                    out %= MOD;
                    done = true;
                    et.insert(inp[i].b+1);
                }
            }
        }
        if (!done) {
//w<< "New" s inp[i].a s inp[i].b<<e;
            out += X + Y*(inp[i].b - inp[i].a);
            out %= MOD;
            et.insert(inp[i].b+1);
        }
    }
    w<< out<<e;
}
