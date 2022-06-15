#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN=100, mxX=1e6, mod=1e9+7;
int n, x, c[mxN+1];
int dp[mxX+1];
 
int main() {
	cin >> n>> x;
	for(int i=0;i<n; i++) {
		cin >> c[i];
	}
	
	dp[0]=1;
	for(int i=1; i<=x; i++) {
		for(int j=0; j<n; j++) {
			if(i>=c[j]) {
				dp[i] = (dp[i] + dp[i-c[j]])%mod;	
			}
		}
	}
	cout << dp[x];
}