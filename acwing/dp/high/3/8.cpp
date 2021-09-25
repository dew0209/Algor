/*
 * 二位费用背包问题
 *  N 个物品 V 的背包 M 背包最大能够承受的重量
 *  f[i][j][k]：前i个物品，体积 <= j,重量 <= k 的所有选法，其值为所有选法中，价值最大的选法
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1010;

int n,m,k;
int f[N][N];

int main(){
    cin >> n >> m >> k;
    int a,b,c;
    for(int i = 0;i < n;i++){
        cin >> a >> b >> c;
        for(int j = m;j >= a;j--)
            for(int t = k;t >= b;t--){
                f[j][t] = max(f[j][t],f[j - a][t - b] + c);
            }
    }
    cout << f[m][k] << endl;

    return 0;
}