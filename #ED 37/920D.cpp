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
//#define int ll
//500,000,000 operations
const int MAXN = 5000, INF = 1000000000;
//Global Variables
int N, K, V, a[MAXN], sum, b1 = -1, b2 = -1;
bool reach[MAXN];
vector<int> have, dp[MAXN];

void transfer (int b, int d) {
    if (b == d || (a[b]+K-1)/K == 0) return;
    /// transfers all of bucket b to bucket d
    w<< (a[b]+K-1)/K s b+1 s d+1<<e;
    a[d] += a[b];
    a[b] = 0;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> V;
    ffi {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < V) {w<< "NO"<<e; return 0;}
    reach[0] = true;
    have.pb(0);
    ffi {
        int val = a[i]%K;
        //w<< i s ":"; for (int j: have) w s j; w<<e;
        int x = have.size();
        For (l, 0, x) {
            int j = have[l];
            //w<< i s j<<e;
            int go = (j+val)%K;
            if (reach[go]) continue;
            reach[go] = true;
            for (int k: dp[j]) dp[go].pb(k);
            dp[go].pb(i);
            //w<< "added" s go<<e;
            have.pb(go);

        }
    }
    //ffj {w<< j<< ":"; for (int i: dp[j]) w s i; w<<e;}
    int x = V%K;
    if (!reach[x]) {w<< "NO"<<e; return 0;}
    w<< "YES"<<e;
    if (x == 0) {
        b1 = 0, b2 = 1;
        /// transfer everything to b2 and make one scoop from b2 to b1
        ffi transfer(i, b2);
        if (V/K != 0) w<< V/K s b2+1 s b1+1<<e;
    }
    else if (dp[x].size() == N) {
        /// transfer everything to b1 and make one scoop from b1 to b2
        b1 = 0, b2 = 1;
        ffi transfer(i, b1);
        if ((a[b1]-V)/K  != 0) w<< (a[b1]-V)/K s b1+1 s b2+1<<e;
    }
    else {
        b1 = dp[x][0];
        ffi {
            bool good = true;
            for (int j: dp[x]) if (j == i) good = false;
            if (good) b2 = i;
        }
        /// transfer everything from dp[x] to b1
        for (int j: dp[x]) transfer(j, b1);
        /// transfer everything else to b2
        ffi {
            bool good = true;
            for (int j: dp[x]) if (j == i) good = false;
            if (good) transfer(i, b2);
        }
        if (a[b1] == V) {}
        else if (a[b1] < V) {
            if ((V-a[b1])/K != 0) w<< (V-a[b1])/K s b2+1 s b1+1<<e;
        }
        else {
            if ((a[b1]-V)/K != 0) w<< (a[b1]-V)/K s b1+1 s b2+1<<e;
        }
    }
}
