#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
#define a first
#define b second
#define mp make_pair
#define eb emplace_back
#define w cout
#define e endl
#define s <<" "<<
#define int long long
#define c <<" : "<<

const int MAXN = 5000, MOD = 1000000007;

int N, out, curr, have;
string in;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> in; N = in.length();
    ffi {
        /// i is the starting point
        curr = have = 0;
        For (j, i, N) {
            if (in[j] == '(') curr++;
            else if (in[j] == ')') curr--;
            else {
                /// put a close
                curr--; have++;
            }
            while (curr < 0 && have > 0) {curr += 2; have--;}
            if (curr < 0) break;
            if (curr == 0) out++;
        }
    }
    w<< out<<e;
}
