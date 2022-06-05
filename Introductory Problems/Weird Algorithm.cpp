#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9
 
int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    cout << n << " ";
    while(1) {
        if(n == 1) break;
        if(n%2 == 0) {
            n /= 2;
            cout << n << " ";
        }
        else {
            n*=3;
            n++;
            cout << n << " ";
        }
    }