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
const int MAXN=1000001, INF=1000000000000000000;
///500,000,000
int N, mid;

bool works() {
    int V = 0, P = 0, have = N;
    while (have > 0) {
        int vt = min(have, mid);
        V += vt;
        have -= vt;
        int pt = have/10;
        P += pt;
        have -= pt;
    }
    return V >= (N+1)/2;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int a = 1, b = INF;
    while (a != b) {
        mid = (a+b)/2;
        if (works()) b = mid;
        else a = mid+1;
    }
    w<< a<<e;
}