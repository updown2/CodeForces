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

int N, K, a;
string out;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K; a = (N-K)/2;
    while (out.size() < N) {
        For(i, 0, a) out += '0';
        out += '1';
    }
    while (out.size() > N) out.pop_back();
    w<< out<<e;
}
