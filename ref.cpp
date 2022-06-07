#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), apt(m);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<m; i++) {
        cin >> apt[i];
    }
    sort(a.begin(), a.end());
    sort(apt.begin(), apt.end());

    int ans = 0, pos = 0;
    for(int i=0; i<m; i++) {
        while(pos < m && a[pos] < apt[i]-k) {
            pos++;
        }
        if(pos < m && a[pos] <= apt[i]+k) {
            ans++;
            pos++;
        }
    }
    cout << ans;


}