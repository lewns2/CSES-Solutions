#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n; cin >> n;
    vector<int> arr, pos(n+1);
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        arr.push_back(a);
        pos[a] = i;
    }

    int ans = 1;
    for(int i=2; i<=n; i++) {
        if(pos[i] < pos[i-1]) {
            ans++;
        }
    }
    cout << ans;
}