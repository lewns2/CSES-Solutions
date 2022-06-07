#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN = 1e5+50;
int n, m;
vector<int> arr[mxN];
int vis[mxN];
bool possible = true;

void dfs(int v, int pos = 0) {
    vis[v] = pos;

    for(int i=0; i<arr[v].size(); i++) {
        int next = arr[v][i];
        if(vis[next] < 0) {
            dfs(next, pos^1);
        }
        else {
            if(vis[next] == pos) {
                possible = false;
            }
        }
    }
}


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int fr, to; cin >> fr >> to;
        arr[fr].push_back(to);
        arr[to].push_back(fr);
    }    

    memset(vis, -1, sizeof(vis));
    for(int i=1; i<=n; i++) {
        if(vis[i] < 0) {
            dfs(i);
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE";
    }
    else {
        for (int i = 1; i <= n; i++)
        {
            cout << vis[i] + 1 << " ";
        }
    }

}