/*
 * 数字组合
 *   从若干个数中选择一些数，使其和为M
 *   01背包
 *   设f[i][j]：1 ~ i 中进行选择，和为j的所有选择方案的个数
 *   f[i][j] = f[i - 1][j] + f[i - 1][j - c];
 */
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int a[N],g[N];
int f[N];

void solve(){
    cin >> n >> m;
    f[0] = 1;
    for(int i = 1;i <= n;i++){
        int c;cin >> c;
        for(int j = m;j >= c;j--){
            f[j] += f[j - c];
        }
    }
    cout << f[m] << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}