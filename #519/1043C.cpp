#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K+1)
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
//500,000,000 operations
const int MAXN = 100001, INF = 10000000000;
//Global Variables
int N;
string in;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> in; N = in.length();
    For (i, 0, N-1) {
        if (in[i] != in[i+1]) {
            /// swap 0 to i
            w<< 1<< " ";
            For (j, 0, i/2 + 1) swap(in[j], in[i-j]);
        }
        else w<< 0<< " ";
        //w<<e<<in<<e;
    }
    if (in[N-1] == 'a') w<< 1<<e;
    else w<< 0<<e;
}
