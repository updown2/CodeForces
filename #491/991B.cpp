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
int N, mid, scores[MAXN];

bool works() {
    int cop[MAXN];
    ffi cop[i] = scores[i];
    For (i, 0, mid) cop[i] = 5;
    int tot = 0;
    ffi tot += cop[i];
    if (tot/N  < 4) return false;
    if (tot/N >= 5) return true;
    if (tot%N >= (N+1)/2) return true;
    return false;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi cin >> scores[i];
    sort(scores, scores+N);
    int a = 0, b = N;
    while (a != b) {
        mid = (a+b)/2;
        if (works()) b = mid;
        else a = mid+1;
    }
    w<< a<<e;
}