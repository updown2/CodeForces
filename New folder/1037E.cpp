/*
Work backwards and remove edges instead of adding them
*/
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
#define e endl //"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=200000, INF=1000000000, MOD = 1000000007;
///500,000,000
int N, M, K;
stack<int> ans;
set<pair<int, int> > going; /// (# of friends, node)
set<pair<int, int> >::iterator it, it2;
set<int> adj[MAXN];
vector<pair<int, int> > edges;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    ffj {
        int a, b; cin >> a >> b; a--; b--;
        edges.pb(mp(a, b));
        adj[a].insert(b); adj[b].insert(a);
    }
    ffi going.insert(mp(adj[i].size(), i));
    ffj {
        if (going.empty()) {ans.push(0); continue;}
        /// delete nodes
        while (!going.empty()) {
            it = going.begin();
            if ((*it).a >= K) break;
            int i = (*it).b;
            for (int k: adj[i]) {
                it2 = going.find(mp(adj[k].size(), k));
                adj[k].erase(i);
                going.erase(it2);
                going.insert(mp(adj[k].size(), k));
            }
            adj[i].clear();
            going.erase(it);
        }
        ans.push(going.size());
        /// remove one edge
        int a = edges[M-j-1].a, b = edges[M-j-1].b;
        //w<< a s b<<e;
        if (adj[a].find(b) != adj[a].end()) {
            //w<< "IN"<<e;
            it = going.find(mp(adj[a].size(), a));
            assert(it != going.end());
            going.erase(it);
            it = going.find(mp(adj[b].size(), b));
            going.erase(it);
            adj[a].erase(b); adj[b].erase(a);
            going.insert(mp(adj[a].size(), a));
            going.insert(mp(adj[b].size(), b));
        }
    }
    ffj {w<< ans.top() << e; ans.pop();}
}
