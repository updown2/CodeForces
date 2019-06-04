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
//#define c <<" : "<<e;

const int MAXN = 300000;

int N, inp[MAXN], loc[MAXN];
vector<pair<int, int> > ch;

main() {
  //ifstream cin("test.in");
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> N; ffi {cin >> inp[i]; inp[i]--; loc[inp[i]] = i;}
  //ffi w<< inp[i]<< " "; w<<e; ffi w<< loc[i]<< " "; w<<e; w<<e;
  ffi if (inp[i] != i) {
      if (abs(loc[i]-i) < N/2) {
        /// three cases
        if (i+1 > N/2) {
            ch.emplace_back(1, 1+i);
            ch.emplace_back(1, 1+loc[i]);
            ch.emplace_back(1, 1+i);
        }
        else if (loc[i]+1 <= N/2) {
            ch.emplace_back(1+loc[i], N);
            ch.emplace_back(1+i, N);
            ch.emplace_back(1+loc[i], N);
        }
        else {
            //w<< 1 s i+1 s 1+loc[i] s N<<e;
            ch.emplace_back(i+1, N);
            ch.emplace_back(1, N);
            ch.emplace_back(1, 1+loc[i]);
            ch.emplace_back(1, N);
            ch.emplace_back(i+1, N);
        }
      }
    else ch.pb(mp(i+1, loc[i]+1));
    inp[loc[i]] = inp[i];
    swap(loc[i], loc[inp[i]]);
    inp[i] = i;
    //ffi w<< inp[i]<< " "; w<<e; ffi w<< loc[i]<< " "; w<<e; w<<e;
  }
  w<< ch.size()<<e;
  for (auto i: ch) {
        w<< i.a s i.b<<e;
        assert(abs(i.a-i.b) >= N/2);
  }
}
