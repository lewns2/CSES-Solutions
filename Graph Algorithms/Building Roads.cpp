#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 2e18
#define INF 1e9

const int mxN = 1e5;
int n, m;
vector<int> arr[mxN+50];
int par[mxN+50];

int find(int x) {
    if(par[x] == x) return x;

    return par[x] = find(par[x]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return false;
    if(a < b) swap(a, b);
    par[a] = b;

    return true;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        par[i] = i;
    }

    for(int i=0; i<m; i++) {
        int fr, to; cin >> fr >> to;
        merge(fr, to);
    }

    vector<pair<int, int>> ans;
    for(int i=1; i<n; i++) {
        if(merge(i, i+1)) {
            ans.push_back({i, i+1});
        }
    }

    cout << ans.size() << "\n";
    for(auto x : ans) {
        cout << x.first << " " << x.second << "\n";
    }
    
}
