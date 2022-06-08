#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN = 1e5 + 10;
int n, m;
vector<int> arr[mxN];
int degree[mxN];


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
    
    int cnt = n;
    vector<int> ans;
    while(q.size()) {
        int now = q.front();
        q.pop();
        cnt--;

        ans.push_back(now);

        for(auto x : arr[now]) {
            int next = x;
            if(--degree[next] == 0) {
                q.push(next);
            }
        }
    }

    if(cnt) {
        cout << "IMPOSSIBLE";
    }
    else {
        for(auto x : ans) {
            cout << x << " ";
        }
    }

}