#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n; cin >> n;
    ll ans = -1e9, mx = -1e9;
    for(int i=0; i<n; i++) {
        ll a; cin >> a;
        mx = max(a, a+mx);
        ans = max(ans, mx);
    }

    cout << ans;
    
}
