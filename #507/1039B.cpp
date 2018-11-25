#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 1, N+1)
#define ffj For(j, 0, N)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 201, INF = 100000000000000;
//Global Variables
int N, K, a, b;

void update() {
    a = max((int)1, a-K); b = min(N, b+K);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    srand (time(NULL));
    a = 1, b = N;
    while (true) {
        while (b-a+1 > 4*K+1) {
            int mid = (a+b)/2;
            w<< a s mid<<e;
            string in; cin >> in;
            if (in[0] == 'B' || (in[0] == 'Y' && a == mid)) return 0;
            if (in[0] == 'Y') b = mid;
            else a = mid+1;
            update();
        }
        /// make a guess
        int x = rand() % (b-a+1) + a;
        //w << "for reference" s a s b c x<<e;
        w<< x s x<<e;
        string in; cin >> in;
        if (in[0] == 'B' || in[0] == 'Y') return 0;
        update();
    }
}
