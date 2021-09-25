/*
 * 装箱问题：
 *  箱子的容量为V
 *  这一题将体积视为价值即可,求的是剩余体积的最小值，那么相对的，所装的物品体积应该越大，这样剩余的就越小
 *  设f[i][j]: 1~i中选，体积 <= j
 *  f[i][j] = max(f[i - 1][j],f[i - 1][j - v[i]] + v[i])
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n,m;
int a[N],w[N];
int f[N];

void solve(){
    cin >> m >> n;
    for(int i = 1;i <= n;i++){
        int v;cin >> v;
        for(int j = m;j >= v;j--){
            f[j] = max(f[j],f[j - v] + v);
        }
    }
    cout << m - f[m] << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}