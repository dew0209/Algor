//dp


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n,m,k;
int f[N][N];
//精灵球数量 伤害值
int v[N],w[N];

int main(){
    
    cin >> n >> m >> k;
    
    for(int i = 0;i < k;i++){
        cin >> v[i];cin >> w[i];
    }
    
    for(int i = 0;i < k;i++){
        for(int j = n;j >= v[i];j--){
            for(int t = m;t >= w[i];t--){
                f[j][t] = max(f[j][t],f[j - v[i]][t - w[i]] + 1);
            }
        }
        
    }
    
    int res = f[n][m - 1];
    
    int ans = 0;
    
    for(int i = 0;i < m;i++){
        if(f[n][i] == res){
            ans = i;
            break;
        }
    }
    cout << res << ' ' << (m - ans) << endl;
    return 0;
}