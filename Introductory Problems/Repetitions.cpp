#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define INFL 2e18
#define INF 1e9
 
int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    char x = s[0];
    int tmp = 0;
    int ans = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == x) {
            tmp++;
        }
        else {
            x = s[i];
            ans = max(ans, tmp);
            tmp = 1;
        }
    }
    ans = max(ans, tmp);
    cout << ans;
}