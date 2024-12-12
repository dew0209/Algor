//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 410;

int n;
int g[N];
int sum[N];
int f[N][N];
int d[N][N];

int main(){
    
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> g[i];
        g[i + n] = g[i];
    }
    
    for(int i = 1;i <= 2 * n;i++){
        sum[i] = sum[i - 1] + g[i];
    }
    
    memset(f,0x3f,sizeof f);
    for(int i = 0;i <= 2 * n;i++){
        f[i][i] = 0;
    }
    for(int len = 1;len <= n;len++){
        for(int l = 1;l + len - 1 <= 2 * n;l++){
            int r = l + len - 1;
            for(int k = l;k < r;k++){
               f[l][r] = min(f[l][r],f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
               d[l][r] = max(d[l][r],d[l][k] + d[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }
    
    int res = 0x3f3f3f3f;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        res = min(res,f[i][i + n - 1]);
        ans = max(ans,d[i][i + n - 1]);
    }
    cout << res << endl;
    cout << ans << endl;
    return 0;
}