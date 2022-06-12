#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n; cin >> n;
    ll mx = 0;
    vector<ll> arr;
    for(int i=0; i<n; i++) {
        ll x; cin >> x;
        mx = max(mx, x);
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    ll mid = arr[n/2];
    ll ans = 0;
    for(int i=0; i<n; i++) {
        ans += abs(arr[i] - mid);
    }
    cout << ans;
}
