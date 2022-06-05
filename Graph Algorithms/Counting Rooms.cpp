#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9
 
const int mxN = 1e3;
const int dx[4] ={1, -1, 0, 0}, dy[4]= {0, 0, 1, -1};
int vis[mxN][mxN];
char arr[mxN][mxN];
int n, m;
 
bool e(int i, int j) {
    return i>=0 && i<n && j>=0 && j<m && arr[i][j] == '.';
}
 
void dfs(int x, int y) {
    vis[x][y] = true;
 
    for(int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
 
        if(e(nx, ny) && !vis[nx][ny]) {
            dfs(nx, ny);
        }
    }
}
 
 
int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        for(int j=0; j<m; j++) {
            arr[i][j] = s[j];
        }
    }
 
    memset(vis, 0, sizeof(vis));
 
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j] && arr[i][j] == '.') {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
 
}