#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+40;
int n, m;
vector<pair<int, pair<int, int>>> arr;
int par[mxN];

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
        int fr, to, val; cin >> fr >> to >> val;
        arr.push_back({val, {fr, to}});
    }

    sort(arr.begin(), arr.end());
    
    ll ans = 0;
    int cnt = n;
    for(int i=0; i<arr.size(); i++) {
        int c = arr[i].first;
        int a = arr[i].second.first;
        int b = arr[i].second.second;

        if(merge(a, b)) {
            ans += c;
            n--;
        }
    }

    if(n == 1) cout << ans;
    else cout << "IMPOSSIBLE";
}

