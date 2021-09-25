/*
 * 采药：
 *    对于每个药，有两种选择的方案：1.不选，2.选择
 *    设f[i][j]：表示为从1~i中选择，时间 <= j 的所有选择方案，其值为选择方案中价值最大的一个
 *    f[i][j] = max(f[i - 1][j],f[i - 1][j - a[i]] + w[i])
 *
 *    优化：将体积从大到小枚举，可以将f[][]降低一维
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int a[N],w[N];
int f[N];

void solve(){
    cin >> m >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> w[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= a[i];j--){
            f[j] = max(f[j],f[j - a[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();
    return 0;
}