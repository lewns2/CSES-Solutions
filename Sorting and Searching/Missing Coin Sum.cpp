#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9
 
 
int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n; cin >> n;
    vector<ll> arr;
    for(int i=0; i<n; i++) {
        ll a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
 
    ll ans = 1;
    for(int i=0; i<n; i++) {
        if(arr[i] > ans) {
            break;
        }
        ans += arr[i];
    }
    cout << ans;
}