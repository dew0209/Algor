#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define fi first
#define se second

using namespace std;

const int N = 100010;

int n,m;
int q[110][110];
int p[110][110];

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> q[i][j];
        }
    }
    vector<pair<int,int>> ans;
    for(int i = 1;i < n;i++){
        for(int j = 1;j < m;j++){
            if(q[i][j] && q[i + 1][j] && q[i][j + 1] && q[i + 1][j + 1]){
                p[i][j] = p[i + 1][j] = p[i][j + 1] = p[i + 1][j + 1] = 1;
                ans.push_back({i,j});
            }
        }
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++){
            if(q[i][j] ^ p[i][j]){
                cout << -1 << endl;
                return;
            }
        }
    cout << ans.size() << endl;
    for(auto c : ans){
        cout << c.fi << ' ' << c.se << endl;
    }
}

int main(){
    solve();
    return 0;
}