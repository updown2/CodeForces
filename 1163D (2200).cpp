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

const int MAXN = 1001, INF = 1000000000;
int N, tat=1, out = -INF, dp[MAXN][MAXN]; /// dp[letter][tree node] = max sum
string have, A, B;
queue<int> n1;
bool vis[MAXN];

struct Trie{
    int nxt[26], val, bck;
    Trie() {
        val = 0; For(i, 0, 26) nxt[i] = -1; bck = -1;
    }
} tree[MAXN];
void add(string use, int ind, int node, int v) {
    if (ind == use.length()) {
        tree[node].val += v;
        return;
    }
    if (tree[node].nxt[use[ind]-'a'] == -1) {
        tree[node].nxt[use[ind]-'a'] = tat;
        tat++;
    }
    node = tree[node].nxt[use[ind]-'a'];
    ind++;
    add(use, ind, node, v);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> have >> A >> B; N = have.length();
    string use = " ";
    For(i, 0, 26) {use[0] = 'a'+i; add(use, 0, 0, 0);}
    For (i, 0, 27) tree[i].bck = 0;
    add(A, 0, 0, 1); add(B, 0, 0, -1);
    /// bfs to set backwards edges and fill up all 26 forward edges
    n1.push(0);
    while (!n1.empty()) {
        int x = n1.front(); n1.pop();
        if (vis[x]) continue;
        vis[x] = true;
        tree[x].val += tree[tree[x].bck].val;
        //w<< x s tree[x].val<<e;
        For(i, 0, 26) {
            int cop = x;
            while (tree[cop].nxt[i] == -1) cop = tree[cop].bck;
            tree[x].nxt[i] = tree[cop].nxt[i];
            if (tree[tree[x].nxt[i]].bck == -1) {
                tree[tree[x].nxt[i]].bck = tree[tree[x].bck].nxt[i];
            }
            n1.push(tree[x].nxt[i]);
        }
    }
    For (i, 0, MAXN) For(j, 0, MAXN) dp[i][j] = -INF;
    dp[0][0] = 0;
    ffi For(j, 0, tat) {
        /// push dp[i][j]
        if (have[i] == '*') {
            /// try all 26 letters
            For (k, 0, 26) {
                int j2 = tree[j].nxt[k];
                dp[i+1][j2] = max(dp[i+1][j2], dp[i][j]+tree[j2].val);
            }
        }
        else {
            int j2 = tree[j].nxt[have[i]-'a'];
            dp[i+1][j2] = max(dp[i+1][j2], dp[i][j]+tree[j2].val);
        }
    }
    For (j, 0, tat) out = max(out, dp[N][j]);
    w<< out<<e;
}
