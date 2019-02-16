/*
https://codeforces.com/blog/entry/3571
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, m)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 1000;
//Global Variables
int N, m, edges[100000][3], root[MAXN], siz[MAXN], Scnt, Mtook;
bool vis[MAXN], take[100000];

int top(int at) {
    if (root[at] == at) return at;
    return top(root[at]);
}
void combine(int a, int b) {
    if (siz[a] > siz[b]) {
        root[b] = a;
        siz[a] += siz[b];
    }
    else {
        root[a] = b;
        siz[b] += siz[a];
    }
}

main() {
	//ifstream cin ("test.in");
	ios_base::sync_with_stdio; cin.tie(0);
	cin >> N >> m;
	ffi {root[i] = i, siz[i] = 1;}
	ffj {
        int a, b; char d; cin >> a >> b >> d; a--; b--;
        edges[j][0] = a, edges[j][1] = b;
        if (d == 'S') edges[j][2] = 1;
	}
	if (N%2 != 1) {w<<-1<<e; exit(0);}
	ffj if (edges[j][2] == 1) { /// if it is a S
        int a = top(edges[j][0]), b = top(edges[j][1]);
        if (a == b) continue;
        Scnt++;
        combine(a, b);
	}
	if (Scnt < N/2) {w<< -1<<e; exit(0);}
	ffj if (edges[j][2] == 0) { /// if it is a M
        int a = top(edges[j][0]), b = top(edges[j][1]);
        if (a == b) continue;
        take[j] = true;
        combine(a, b);
	}
	ffi {root[i] = i, siz[i] = 1;}
	ffj if (take[j]) { /// the only option is M
        int a = top(edges[j][0]), b = top(edges[j][1]);
        if (a == b) continue;
        Mtook++;
        combine(a, b);
	}
	ffj if (edges[j][2] == 0 && Mtook < N/2) { /// if it is a M
        int a = top(edges[j][0]), b = top(edges[j][1]);
        if (a == b) continue;
        take[j] = true;
        Mtook++;
        combine(a, b);
	}
	if (Mtook < N/2) {w<< -1<<e; exit(0);}
	ffj if (edges[j][2] == 1) { /// if it is a S
        int a = top(edges[j][0]), b = top(edges[j][1]);
        if (a == b) continue;
        take[j] = true;
        combine(a, b);
	}
	w<< N-1<<e;
	ffj if (take[j]) w<< j+1 << " "; w<<e;
}
