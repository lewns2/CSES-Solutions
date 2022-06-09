#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9
 
const int mxN = 1e5 + 50;
int n, m;
vector<int> arr[mxN];
bool vis[mxN], act[mxN];
int p[mxN], dp[mxN];
 
void dfs(int v) {
    vis[v] = true;
    
    for(auto next : arr[v]) {
        if(!vis[next]) {
            dfs(next);
        }
        if(dp[next] + 1 > dp[v]) {
            dp[v] = dp[next]+1;
            p[v] = next;
        }
    }
}
 
int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int fr, to; cin >> fr >> to;
        arr[fr].push_back(to);
    }
 
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=n; i++) {
        dp[i] = -1e9;
    }
    dp[n] = 1;
    
    dfs(1);
 
    if(dp[1] < 0) {
        cout << "IMPOSSIBLE";
    } 
    else {
        vector<int> ans;
        ans.push_back(1);
        int u = p[1];
        while(u != n) {
            ans.push_back(u);
            u = p[u];
        }
        ans.push_back(n);
        cout << ans.size() << "\n";
        for(auto x : ans) {
            cout << x << " ";
        }
    }
 
}