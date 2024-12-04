//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210;

int n,m;
int f[N][N];
int g[N][N];

void solve(){
    
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> g[i][j];
        }
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            f[i][j] = max(f[i - 1][j],f[i][j - 1]) + g[i][j];
        }
    }
    cout << f[n][m] << endl;
}

int main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}