#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+50;
int n, m;
vector<pair<int, int>> arr[mxN];
ll dist[mxN][2];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int fr, to, val; cin >> fr >> to >> val;
        arr[fr].push_back({to, val});
    }

    memset(dist, 0x3f, sizeof(dist));
    dist[1][0] = 0;

    priority_queue<pair<ll, pair<ll, int>>> pq;
    pq.push({dist[1][0], {1, 0}});

    while(pq.size()) {
        ll cost = -pq.top().first;
        ll now = pq.top().second.first;
        int cnt = pq.top().second.second;
        pq.pop();

        if(cost > dist[now][cnt]) continue;

        for(auto x : arr[now]) {
            int next = x.first;
            int nextcost = x.second;
            
            if(dist[next][cnt] > dist[now][cnt] + nextcost) {
                dist[next][cnt] = dist[now][cnt] + nextcost;
                pq.push({-dist[next][cnt], {next, cnt}});
            }
            if(cnt == 0) {
                if(dist[next][cnt+1] > dist[now][cnt] + nextcost/2) {
                    dist[next][cnt+1] = dist[now][cnt] + nextcost/2;
                    pq.push({-dist[next][cnt+1], {next, cnt+1}});
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]);


}