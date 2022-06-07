#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

const int mxN = 1e5+10;
int n, m;
vector<pair<int, int>> arr[mxN];
ll dist[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int fr, to, val; cin >> fr >> to >> val;
        arr[fr].push_back({to, val});
    }

    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<pair<ll, ll>> pq;
    pq.push({dist[1], 1});

    while(pq.size()) {
        ll now = pq.top().second;
        ll cost = -pq.top().first;
        pq.pop();

        if(cost > dist[now]) continue;

        for(auto x : arr[now]) {
            int next = x.first;
            int nextcost = x.second;
            if(dist[next] > dist[now] + nextcost) {
                dist[next] = dist[now] + nextcost;
                pq.push({-dist[next], next});
            }
        }
    }

    for(int i=1; i<=n; i++) {
        cout << dist[i] << " ";
    }


}