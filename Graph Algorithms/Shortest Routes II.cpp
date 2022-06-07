#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN = 550;
int n, m, q;
ll dist[mxN][mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m >> q;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            dist[i][j] = 0x3f;
        }
        dist[i][i] = 0;
    }

    for(int i=0; i<m; i++) {
        ll fr, to, val; cin >> fr >> to >> val;
        dist[fr][to] = min(dist[fr][to], val);
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q--) {
        int a, b; cin >> a >> b;
        if(dist[a][b] == INF) {
            cout << -1 << "\n";
        }
        else {
            cout << dist[a][b] << "\n";
        }
    }
}