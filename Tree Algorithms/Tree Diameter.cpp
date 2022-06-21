#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 2e5+20;
int n, dist[mxN];
vector<int> arr[mxN];

void dfs(int v, int p = -1) {

    for(auto next : arr[v]) {
        if(next != p) {
            dist[next] = dist[v] + 1;
            dfs(next, v);
        }
    }
}



int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int fr, to; cin >> fr >> to;
        arr[fr].push_back(to);
        arr[to].push_back(fr);
    }
    dfs(1);
    
    int pos = 0, mx = 0, ans = 0;
    for(int i=1; i<=n; i++) {
        if(dist[i] > mx) {
            mx = dist[i];
            pos = i;
        }
    }
    
    memset(dist, 0, sizeof(dist));
    dfs(pos);
    mx = 0;
    for(int i=1; i<=n; i++) {
        mx = max(dist[i], mx);
    }
    ans += mx;
    cout << ans;
}