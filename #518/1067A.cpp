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
const int MAXN=100000, INF=1000000000, MOD = 998244353;
///500,000,000
int N, inp[MAXN], dp[MAXN][200][3], pup[200], pdo[200];

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi {cin >> inp[i]; inp[i]--;}
    if (inp[0] == -2) For (i, 0, 200) dp[0][i][0] = 1;
    else dp[0][inp[0]][0] = (int)1;
    For (i, 1, N) {
        pup[0] = dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2];
        pup[0] %= MOD;
        For (j, 1, 200) {pup[j] = pup[j-1]+ dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2]; pup[j] %= MOD;}
        pdo[199] = dp[i-1][199][1] + dp[i-1][199][2];
        pdo[199] %= MOD;
        for (int j=198; j>=0; j--) {pdo[j] = pdo[j+1] + dp[i-1][j][1] + dp[i-1][j][2]; pdo[j] %= MOD;}

        if (inp[i] == -2) {
            For (val, 0, 200) {
                if (val != 0) dp[i][val][0] = pup[val-1];
                dp[i][val][1] = dp[i-1][val][0]+dp[i-1][val][1]+dp[i-1][val][2];
                dp[i][val][1] %= MOD;
                if (val != 199) dp[i][val][2] = pdo[val+1];
            }
        }
        else {
            int val = inp[i];
            if (val != 0) dp[i][val][0] = pup[val-1];
            dp[i][val][1] = dp[i-1][val][0]+dp[i-1][val][1]+dp[i-1][val][2];
            dp[i][val][1] %= MOD;
            if (val != 199) dp[i][val][2] = pdo[val+1];
        }
    }
    if (inp[N-1] == -2) {
        int out = 0;
        For (i, 0, 200) {out += dp[N-1][i][1] + dp[N-1][i][2]; out %= MOD;}
        w<< out<<e;
    }
    else {
        w<< (dp[N-1][inp[N-1]][2] + dp[N-1][inp[N-1]][1])%MOD <<e;
    }
    //ffi {For (j, 0, 3) w<< i s j c dp[i][j][0] s dp[i][j][1] s dp[i][j][2]<<e; w<<e;}
}
