/*
 * 潜水员
 * f[i][j][k]：前i个气缸，氧气 >= j 氮气 >= k 的所有选法，其值为承重最小的选法的值
 *
 * 表示不一样：便是为至少的时候，注意初始化值的不同。并且在 j < 当前气缸的氧气...这也是满足题意的。
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n,m,k;
int f[N][N];

int main(){
    cin >> n >> m >> k;
    int a,b,c;
    memset(f,0x3f,sizeof f);
    f[0][0] = 0;
    for(int i = 0;i < k;i++){
        cin >> a >> b >> c;
        for(int j = n;j >= 0;j--){
            for(int t = m;t >= 0;t--)
                f[j][t] = min(f[j][t],f[max(j - a,0)][max(t - b,0)] + c);
        }
    }
    cout << f[n][m] << endl;

    return 0;
}