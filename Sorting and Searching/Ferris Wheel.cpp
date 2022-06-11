#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 1e18
#define INF 1e9


int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int n, k; cin >> n >> k;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    int lo = 0, hi = n-1;
    
    while(lo <= hi) {
        if(lo == hi) {
            if(arr[lo] < k) ans++;
            break;
        } 
        else {
            ans++;
            if(arr[lo] + arr[hi] > k) {
                hi--;
            }
            else {
                lo++, hi--;
            }
        }
    }
    cout << ans;
}