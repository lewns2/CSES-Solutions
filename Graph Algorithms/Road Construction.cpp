#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+50;
int n, m;
vector<pair<int, int>> arr;
int par[mxN], mx = 0;
map<int, int> mp;

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
    mp[b] += mp[a];
    mx = max(mx, mp[b]);
    return true;
}

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        par[i] = i;
        mp[i] = 1;
    }

    for(int i=0; i<m; i++) {
        int fr, to; cin >> fr >> to;
        arr.push_back({fr, to});
    }
    
    int ans1=n;
    for(int i=0; i<arr.size(); i++) {
        int a = arr[i].first;
        int b = arr[i].second;
        if(merge(a, b)) {
            ans1--;
        }
        cout << ans1 << " " << mx << "\n";
    }
}

