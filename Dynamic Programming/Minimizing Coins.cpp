#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN=1e6+20, MOD = 1e9+7;
int dp[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n, x; cin >> n >> x;
    vector<int> c;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        c.push_back(a);
    }
    
    for(int i=1; i<=x; i++) {
        dp[i] = 1e9; 
        for(int j=0; j<n; j++) {
            if(i >= c[j]) {
                dp[i] = min(dp[i], dp[i-c[j]]+1)%MOD;
            }
        }
    }
    if(dp[x] == 1e9) cout << -1;
    else cout << dp[x];

}

