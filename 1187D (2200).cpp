#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=300000;

int T, N, tree[4*MAXN+1];
bool good;

void update(int ind, int L, int R, int x, int v) {
    if (x < L || R < x) return;
    if (L == R) {
        tree[ind] = v;
        return;
    }
    update(ind*2, L, (L+R)/2, x, v); update(ind*2+1, (L+R)/2+1, R, x, v);
    tree[ind] = min(tree[ind*2], tree[ind*2+1]);
}
pair<int, int> query(int ind, int L, int R, int v) {
    if (L == R) {
        if (tree[ind] <= v) return mp(tree[ind], L);
        return mp(MAXN+1, MAXN+1);
    }
    if (tree[ind*2] <= v) return query(ind*2, L, (L+R)/2, v);
    return query(ind*2+1, (L+R)/2+1, R, v);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    For (t, 0, T) {
        cin >> N;
        good = true;
        ffi {
            int a; cin >> a;
            update(1, 0, N-1, i, a);
        }
        ffi {
            int b; cin >> b;
            pair<int, int> x = query(1, 0, N-1, b); /// (value, index) of the first value that is <= b
            //w<< "with " << b s ", got" s x.a s x.b+1<<e;
            if (x.a != b) good = false;
            else {
                update(1, 0, N-1, x.b, MAXN+1);
            }
        }
        if (good) w<< "YES"<<e;
        else w<< "NO"<<e;
    }
}
