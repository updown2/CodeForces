#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define a first
#define b second
#define mp make_pair
#define pb push_back
#define w cout
#define e endl
#define s <<" "<<
#define int long long
#define c <<" : "<<

const int MAXN = 200000;

int N, M, Ta, Tb, K, A[MAXN], B[MAXN], out;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> Ta >> Tb >> K;
    ffi {cin >> A[i]; A[i] += Ta;} ffj cin >> B[j];
    if (N <= K) {
        /// can delete all
        w<< -1<<e;
        return 0;
    }
    For (i, -1, N-1) {
        /// deleting the first i+1 (0...i) points
        if (i+1 > K) break;
        if (B[M-1] < A[i+1]) {
            /// can delete all
            //w<< "p1" s (i+1) s B[M-1] s A[i+1]<<e;
            w<< -1<<e;
            return 0;
        }
        /// find next point in B
        int a = 0, b = M-1;
        while (a != b) {
            int mid = (a+b)/2;
            if (B[mid] >= A[i+1]) b = mid;
            else a = mid+1;
        }
        if (i+1+(M-a) <= K) {
            /// can delete all
            //w<< "p2" s (i+1) s a+1<<e;
            w<< -1<<e;
            return 0;
        }
        //w<< "from a:" s (i+1) c (B[a+K-(i+1)]) <<e;
        out = max(out, B[a+K-(i+1)]);
    }
    w<< out+Tb<<e;
}

