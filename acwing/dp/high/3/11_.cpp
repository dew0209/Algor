/*
 * 背包问题求具体方案数
 *  f[i]:体积花费恰好为i时的选法，其值为最大价值
 *  g[i]：体积花费恰好为i时的方案数量
 *  4 5
 *  1 2
 *  2 4
 *  3 4
 *  4 6
 *
 *  f数组每轮
 *  0 2 -1044266557 -1044266557 -1044266557 -1044266557  1
 *  0 2      4           6      -1044266553 -1044266553  2
 *  0 2      4           6       6            8          3
 *  0 2      4           6       6            8          4
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010,MOD = 1e9 + 7;

int n,m;
int f[N];
int g[N];

int main(){
    cin >> n >> m;
    memset(f,-0x3f,sizeof f);
    f[0] = 0;
    g[0] = 1;
    int a,b;
    for(int i = 1;i <= n;i++){
        cin >> a >> b;
        for(int j = m;j >= a;j--){
            int maxv = max(f[j],f[j - a] + b);
            int s = 0;
            if(maxv == f[j])s += g[j];
            if(f[j - a] + b == maxv)s = (s + g[j - a]) % MOD;
            f[j] = maxv,g[j] = s;
        }
    }
    int res = 0;
    for(int i = 1;i <= m;i++){
        if(f[i] > f[res])res = i;
    }
    int sum = 0;
    for(int i = 0;i <= m;i++){
        if(f[i] == f[res])sum = (sum + g[i]) % MOD;
    }
    cout << sum << endl;

    return 0;
}