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
const int MAXN=100, INF=1000000000000000000;
///500,000,000
int A, B, C, N, X;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B >> C >> N;
    int X = N-A-B+C;
    if (min(A, B) < C) w<<-1<<e;
    else if (max(A, max(B, C)) > N) w<< -1<<e;
    else if (X < 1) w<< -1<<e;
    else w<< X<<e;
}