#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=20, INF=1000000000000000000;
///500,000,000
int out, fac[MAXN];
string in;
set<string> done;

void go(string at) {
    if (done.find(at) != done.end()) return;
    done.insert(at);
    int N = at.length();
    int v = 1;
    int cnt[10];
    For (i, 0, 10) cnt[i] = 0;
    for (char i: at) cnt[i-'0']++;
    /// zeros
    v *= fac[N-1]*(N-cnt[0]);
    For (i, 0, 10) v /= fac[cnt[i]];
    //w<<at s ":" s v<<e;
    out += v;
    /// find other states
    int loc = 0;
    For (i, 0, 10) {
        //w<< at s i s ":" s cnt[i]<<e;
        if (cnt[i] > 1) {
            /// remove 1;
            string curr = at;
            curr.erase(loc, 1);
            //w<< at s "to" s curr<<e;
            go(curr);
        }
        loc += cnt[i];
    }
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    fac[0] = 1;
    For (i, 1, MAXN) fac[i] = fac[i-1]*i;
    cin >> in;
    sort(in.begin(), in.end());
    go(in);
    w<< out<<e;
}