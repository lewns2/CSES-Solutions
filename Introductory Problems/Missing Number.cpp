#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9
 
int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    ll tmp = 0;
    for(int i=0; i<n-1; i++) {
        int x; cin >> x;
        tmp += x;
    }
    cout << n * (n+1) / 2 - tmp;