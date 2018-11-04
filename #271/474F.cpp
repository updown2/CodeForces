#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
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
const int MAXN = 100000;
//Global Variables
int N, Q, inp[MAXN], tgcd[4*MAXN+1], tmin[4*MAXN+1], tcnt[4*MAXN+1];
int gcd(int a, int b) {return (a==0 ? b:gcd(b%a, a));}

void bgcd (int x, int L, int R) {
    if (L == R) {tgcd[x] = inp[L]; return;}
    bgcd(x*2, L, (L+R)/2); bgcd(x*2+1, (L+R)/2+1, R);
    tgcd[x] = gcd(tgcd[x*2], tgcd[x*2+1]);
}
void bcnt (int x, int L, int R) {
    if (L == R) {tmin[x] = inp[L]; tcnt[x] = 1; return;}
    bcnt(x*2, L, (L+R)/2); bcnt(x*2+1, (L+R)/2+1, R);
    tmin[x] = min(tmin[x*2], tmin[x*2+1]);
    if (tmin[x*2] == tmin[x]) tcnt[x] += tcnt[x*2];
    if (tmin[x*2+1] == tmin[x]) tcnt[x] += tcnt[x*2+1];
}
int qgcd (int index, int L, int R, int oL, int oR) {
	if ( (oR < L) || (oL > R) ) return 0;
	if ( (R <= oR) && (L >= oL) ) return tgcd[index];
	return gcd(qgcd(index*2, L, (L+R)/2, oL, oR), qgcd(index*2+1, 1+(L+R)/2, R, oL, oR ) );
}
pair<int, int> qcnt (int index, int L, int R, int oL, int oR, int v) { ///(min, cnt)
	if ( (oR < L) || (oL > R) ) return mp(1000000001, 0);
	if ( (R <= oR) && (L >= oL) ) return mp(tmin[index], tcnt[index]);
	pair<int, int> a = qcnt(index*2, L, (L+R)/2, oL, oR, v), b = qcnt(index*2+1, 1+(L+R)/2, R, oL, oR, v);
	int x = min(a.a, b.a);
	int ret = 0;
	if (a.a == x) ret += a.b;
	if (b.a == x) ret += b.b;
	return mp(x, ret);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; ffi cin >> inp[i];
    bgcd(1, 0, N-1); bcnt(1, 0, N-1);
    cin >> Q;
    For (q, 0, Q) {
        int a, b; cin >> a >> b; a--; b--;
        int x = qgcd(1, 0, N-1, a, b);
        pair<int, int> y = qcnt(1, 0, N-1, a, b, x);
        if (y.a != x) y.b = 0;
        w<< b-a+1-y.b<<e;
    }
}
