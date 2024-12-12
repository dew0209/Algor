//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

const int N = 1010;

int n,m;
int f[N];
int v[N],w[N];
int cnt[N];

int main(){
    
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++){
        cin >> v[i] >> w[i];
    }
    
    memset(f,-0x3f,sizeof f);
    
    f[0] = 0;
    cnt[0] = 1;
    int res = 0;
    for(int i = n;i >= 1;i--){
        for(int j = m;j >= v[i];j--){
            int maxv = max(f[j],f[j - v[i]] + w[i]);
            int ans = 0;
            if(maxv == f[j])ans += cnt[j];
            if(maxv == f[j - v[i]] + w[i])ans = (ans + cnt[j - v[i]]) % MOD;
            f[j] = maxv;
            cnt[j] = ans;
            res = max(res,f[j]);
        }
    }
    
    int ans = 0;
    
    for(int i = 0;i <= m;i++)if(f[i] == res)ans = (ans + cnt[i]) % MOD;
    cout << ans << endl;
    return 0;
}