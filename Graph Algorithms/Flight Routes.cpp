#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5+50;
int n, m, k;
vector<pair<int, int>> arr[mxN];
priority_queue<ll> dist[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m >> k;
    for(int i=0; i<m; i++) {
        int fr, to, val; cin >> fr >> to >> val;
        arr[fr].push_back({to, val});
    }

    dist[1].push(0);
    priority_queue<pair<ll, ll>> pq;
    pq.push({dist[1].top(), 1});

    while(pq.size()) {
        ll cost = -pq.top().first;
        ll now = pq.top().second;
        pq.pop();

        if(cost > dist[now].top()) continue;
        
        for(auto x : arr[now]) {
            int next = x.first;
            int nextcost = x.second;

            if(dist[next].size() < k) {
                ll c = cost + nextcost;
                dist[next].push(c);
                pq.push({-c, next});
            }
            else {
                ll mx = dist[next].top();
                ll c = nextcost + cost;
                if(mx > c) {
                    dist[next].pop();
                    dist[next].push(c);
                    pq.push({-c, next});
                }
                
            }
        }
    }
    vector<ll> ans;
    while(dist[n].size()) {
        ans.push_back(dist[n].top());
        dist[n].pop();
    }

    sort(ans.begin(), ans.end());
    for(auto x : ans) {
        cout << x << " ";
    }
    

}