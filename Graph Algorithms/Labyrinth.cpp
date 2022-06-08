#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INFL 1e18
#define INF 1e9

// D, U, R, L 
const int mxN = 1e3+10, dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m, si, sj, ei, ej;
char arr[mxN][mxN];
int vis[mxN][mxN];

int main() {
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        for(int j=0; j<m; j++) {
            arr[i][j] = s[j];
            if(s[j] == 'A') {
                si = i;
                sj = j;
            }
            else if(s[j] == 'B') {
                ei = i;
                ej = j;
            }
        }
    }

    memset(vis, -1, sizeof(vis));
    bool flag = false;
    queue<pair<int, int >> q;
    q.push({si, sj});

    while(q.size()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for(int k=0; k<4; k++) {
            int x = a+dx[k];
            int y = b+dy[k];
            
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(vis[x][y] < 0) {
                if(arr[x][y] == '.') {
                    vis[x][y] = k;
                    q.push({x, y});
                }
                if(arr[x][y] == 'B') {
                    vis[x][y] = k;
                    flag = true;
                    break;
                }
            }
        }
        if(flag) break;
    }

    if(vis[ei][ej] < 0) {
        cout << "NO";
    }
    else {
        cout << "YES" << "\n";
        vector<char> ans;
        int x = ei, y = ej;
        while(x != si || y != sj) {
            if(vis[x][y] == 0) {
                ans.push_back('D');
                x--;
            }
            else if(vis[x][y] == 1) {
                ans.push_back('U');
                x++;
            }
            else if(vis[x][y] == 2) {
                ans.push_back('R');
                y--;
            }
            else if(vis[x][y] == 3) {
                ans.push_back('L');
                y++;
            }
        }
        cout << ans.size() << "\n";

        reverse(ans.begin(), ans.end());
        for(auto it : ans) {
            cout << it;
        }
    }


    
    
}