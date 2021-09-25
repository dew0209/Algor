/*
 * 庆功会
 * 多重背包
 * f[i][j]：从1~i中选择，金额不超过j的选法，其值为最大价值的选法
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n,m;
int f[6010];
int V[100010],W[100010];

/*void solve(){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int v,w,s;cin >> v >> w >> s;
        for(int j = m;j >= v;j--){
            for(int k = 0;k <= s && k * v <= j;k++){
                f[j] = max(f[j],f[j - k * v] + k * w);
            }
        }
    }
    cout << f[m] << endl;
}*/

//二进制优化版本
void solve1(){
    cin >> n >> m;
    int v,w,s;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        cin >> v >> w >> s;
        int k = 1;
        while(k <= s){
            V[cnt] = v * k;
            W[cnt++] = w * k;
            s -= k;
            k <= 1;
        }
        if(s){
            V[cnt] = s * v;
            W[cnt++] = s * w;
        }
    }
    for(int i = 0;i < cnt;i++){
        for(int j = m;j >= V[i];j--){
            f[j] = max(f[j],f[j - V[i]] + W[i]);
        }
    }
    cout << f[m] << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve1();

    return 0;
}