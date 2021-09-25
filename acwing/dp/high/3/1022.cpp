/*
 * 宠物小精灵之收服
 *  精灵球的数量：n
 *  皮卡丘的体力m
 *  小精灵的个数k
 *  对于每个小精灵：选择或不选择
 *  设f[i][j][k]：1 ~ i 中选择，精灵球 <= j,体力 <= k 的所有选择方案，其值为捕捉最多的方案
 *  f[i][j][k] = max(f[i - 1][j][k],f[i - 1][j - ai][k - bi] + 1)
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 10010;

int n,m,k;
int a[N],b[N];
int f[N][N];

void solve(){
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++){
        int a1,b1;cin >> a1 >> b1;
        for(int j = n;j >= a1;j--)
            for(int t = m;t >= b1;t--){
                f[j][t] = max(f[j][t],f[j - a1][t - b1] + 1);
            }
    }
    cout << f[n][m - 1] << ' ';//收服的最多的小精灵的个数
    for(int i = 0;i < m;i++){
        if(f[n][i] == f[n][m - 1]){
            cout << m - i << endl;
            break;
        }
    }
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}