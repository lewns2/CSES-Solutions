#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 2e5+20;
int n, q;
vector<int> arr[mxN];
int depth[mxN], dp[mxN][30];

void dfs(int v, int d, int p = -1) {
    
    depth[v] = d;
    
    for(auto next : arr[v]) {
        if(next != p) {
            dp[next][0] = v;
            dfs(next, d+1, v);
        }
    }
}

void init() {
    for(int j=1; j<30; j++) {
        for(int i=1; i<=n; i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> q;
    for(int i=2; i<=n; i++) {
        int a; cin >> a;
        arr[i].push_back(a);
        arr[a].push_back(i);
    }
    dfs(1, 1);
    init();

    while(q--) {
        int x, diff; cin >> x >> diff;
        
        for(int i=0; diff; i++) {
            if(diff & 1) {
                x = dp[x][i];
            }
            diff >>= 1;
        }
        if(x == 0) cout << -1 << "\n";
        else cout << x << "\n";
        
    }
}