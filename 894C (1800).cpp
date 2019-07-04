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

const int MAXN = 1001, MOD = 1000000007;

int N, curr;
set<int> vals;
int gcd(int a, int b) {return a==0 ? b:gcd(b%a, a);}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; ffi {int a; cin >> a; curr = gcd(curr, a); vals.insert(a);}
    if (vals.find(curr) == vals.end()) {w<<-1<<e; return 0;}
    w<< 2*N+1<<e<<curr;
    for (auto i: vals) w s i s curr; w<<e;
}
