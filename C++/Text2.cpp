#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, K, M, cost[100000], group[100000], small[100000], out;
map<string, int> index;

int main() {
    cin >> N >> K >> M;
    for (int i=0; i<N; i++) {
        string a;
        cin >> a;
        index[a] = i;
    }
    for (int i=0; i<N; i++) {
        cin >> cost[i];
    }
    for (int i=0; i<K; i++) {
        int size;
        cin >> size;
        for (int j=0; j<size; j++) {
            int word;
            cin >> word;
            word--;
            group[word] = i;
        }
        small[i] = 1000000000;
    }
    for (int i=0; i<N; i++) {
        small[group[i]] = min(small[group[i]], cost[i]);
    }
    for (int i=0; i<M; i++) {
        string a;
        cin >> a;
        out += small[group[index[a]]];
    }
    cout << out << endl;
}
