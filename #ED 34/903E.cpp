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
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 2500;
//Global Variables
int K, N;
bool dup;
string inp[MAXN], ans;
vector<int> diff[MAXN];

main() {
	//ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K >> N;
    ffj {
        cin >> inp[j];
        For (k, 0, N) if (inp[j][k] != inp[0][k]) diff[j].pb(k);
        if (diff[j].size() > 4) {w<<-1<<e; return 0;}
    }
    if (N > 26) dup = true;
    else {
        ffi For (j, i+1, N) if (inp[0][i] == inp[0][j]) dup = true;
    }
    ans = inp[0];
    bool fail;
    vector<int> bad;
    ffi For (j, i+1, N) {
        swap(ans[i], ans[j]);
        fail = false;
        For (k, 1, K) {
            bad.clear();
            for (int l: diff[k]) if (ans[l] != inp[k][l]) bad.pb(l);
            int l = i; if (ans[l] != inp[k][l] && inp[0][l] == inp[k][l]) bad.pb(l);
            l = j; if (ans[l] != inp[k][l] && inp[0][l] == inp[k][l]) bad.pb(l);
            fail = true;
            if (bad.size() == 0 && dup) fail = false;
            else if (bad.size() == 2 && ans[bad[0]] == inp[k][bad[1]] && ans[bad[1]] == inp[k][bad[0]]) fail = false;
            if (fail) break;
        }
        if (!fail) {w<< ans<<e; return 0;}
        swap(ans[i], ans[j]);
    }
    w<<-1<<e;
}
