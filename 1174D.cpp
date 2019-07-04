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

int N, X;
bool bad[1<<18];
vector<int> pre, ans;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> X; bad[X] = true;
    For (i, 1, 1<<N) if (!bad[i]) {
        pre.pb(i);
        bad[i^X] = true;
    }
    int last = 0;
    for (int i: pre) {
        ans.pb(last^i);
        last = i;
    }
    w<< ans.size()<<e;
    for(int i: ans) w<<i<<" ";
    w<<e;
}
