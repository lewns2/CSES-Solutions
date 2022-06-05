#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9
 
const int mxN = 1e5;
vector<int> arr[mxN+10];
int vis[mxN+10];
int n, m;
 
int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int fr, to; cin >> fr >> to;
        arr[fr].push_back(to);
        arr[to].push_back(fr);
    }
 
    memset(vis, -1, sizeof(vis));
    
    queue<int> q;
    q.push(1);
    
    while(q.size()) {
        int now = q.front();
        q.pop();
 
        for(int i=0; i<arr[now].size(); i++) {
            int next = arr[now][i];
            if(vis[next] < 0) {
                vis[next] = now;
                q.push(next);
            }
        }
    }
    if(vis[n] < 0) {
        cout << "IMPOSSIBLE";
        
    }
    else {
        vector<int> ans;
        ans.push_back(n);
        int tr = n;
        while(1) {
            if(tr == 1) break;
            ans.push_back(vis[tr]);
            tr = vis[tr];
        }
 
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(auto x : ans) {
            cout << x << " ";
        }
    }
 
    
 
 
}