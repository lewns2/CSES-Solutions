#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 2e5+10;
int n, vis[mxN], ds[mxN];
vector<int> arr[mxN];

void dfs(int v) {
    vis[v] = 1;
    
    for(auto next : arr[v]) {
        if(!vis[next]) {
            dfs(next);
            ds[v] += ds[next];
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n;

    for(int i=1; i<=n; i++) {
        ds[i] = 1;
    }

    for(int i=2; i<=n; i++) {
        int a; cin >> a;
        arr[i].push_back(a);
        arr[a].push_back(i);
    }

    dfs(1);
    for(int i=1; i<=n; i++) {
        cout << ds[i] - 1 << " ";
    }
    
}