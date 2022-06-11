#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n; cin >> n;
    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({b, a});
    }
    sort(arr.begin(), arr.end());

    int ans = 1;
    int x = arr[0].first;
    for(int i=1; i<arr.size(); i++) {
        int e = arr[i].first;
        int s = arr[i].second;
        if(s >= x) {
            x = e;
            ans++;
        }
    }
    cout << ans;

}
