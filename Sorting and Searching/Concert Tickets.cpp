#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9
 
 
int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n, m; cin >> n >> m;
    multiset<int> ms;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        ms.insert(-x);
    }
    for(int i=0; i<m; i++) {
        int x; cin >> x;
        
        auto it = ms.lower_bound(-x);
        if(it == ms.end()) {
            cout << -1 << "\n";
        }
        else {
            cout << -*it << "\n";
            ms.erase(it);
        }
    }
}