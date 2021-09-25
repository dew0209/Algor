/*
 * 买书
 *  完全背包：每种物品可以无限选择
 *  设f[i][j]：从1 ~ i 中选择，花费为j的所有选择方案数
 *  f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]] + f[i - 1][j - 2a[i]] + ... ;
 *  优化：
 *  f[i][j - a[i]] =        f[i - 1][j - a[i]] + f[i - 1][j - 2a[i]] + ...;
 *  得出：
 *  f[i][j] = f[i - 1][j] + f[i][j - ai];
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int f[N];
int a[] = {10,20,50,100};

void solve(){
    cin >> n;
    f[0] = 1;
    for(int i = 0;i < 4;i++){
        for(int j = a[i];j <= n;j++){
            f[j] += f[j - a[i]];
        }
    }
    cout << f[n] << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}