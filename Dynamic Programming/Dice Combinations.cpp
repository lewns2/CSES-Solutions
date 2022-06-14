#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9

const int mxN=1e6+20, MOD = 1e9+7;
int dp[mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n; cin >> n;
    
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=min(6, i); j++) {
            dp[i] = (dp[i] + dp[i-j])%MOD;
        }
    }
    cout << dp[n];
}

