#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


const int mxN = 1e5 + 50;
int n, m;
vector<int> arr[mxN];
vector<int> rarr[mxN];
vector<vector<int>> scc;
stack<int> st;
int vis[mxN], par[mxN], degree[mxN];
vector<int> connect[mxN];

void dfs(int v) {
    vis[v] = 1;
    for(auto next : arr[v]) {
        if(!vis[next]) {
            dfs(next);
        }
    }
    st.push(v);
}

void rdfs(int v, int node) {
    vis[v] = 1;
    scc[node].push_back(v);
    par[v] = node;
    
    for(auto next : rarr[v]) {
        if(!vis[next]) {
            rdfs(next, node);
        }
        else if(par[v] != par[next]) {
            degree[par[v]]++;
            connect[par[next]].push_back(par[v]);
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int fr, to; cin >> fr >> to;
        arr[fr].push_back(to);
        rarr[to].push_back(fr);
    }

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    while(st.size()) {
        int x = st.top();
        st.pop();

        if(vis[x]) continue;
        scc.resize(++cnt);
        rdfs(x, cnt-1);
    }

    if(cnt == 1) cout << "YES";
    else {
        cout << "NO" << "\n";

        int a = -1, b = -1;

        for(int i=0; i<cnt; i++) {
            if(degree[i] == 0 && a == -1) {
                a = i;
            }
            else {
                b = i;
            }
        }
        cout << scc[b][0] << " " << scc[a][0];
    }
    
}

