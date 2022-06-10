#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5 + 50, MOD = 1e9+7;
int n, m;
vector<int> arr[mxN];
int degree[mxN];
ll dp[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int fr, to; cin >> fr >> to;
        arr[fr].push_back(to);
        degree[to]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }
    dp[1] = 1;
    while(q.size()) {
        int x = q.front();
        q.pop();

        for(auto next : arr[x]) {
            dp[next] = (dp[x] + dp[next]) % MOD;
            if(--degree[next] == 0) {
                q.push(next);
            }
        }
    }

    cout << dp[n];

}