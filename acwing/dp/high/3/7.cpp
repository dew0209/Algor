/*
 * 混合背包
 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;

int n,m;
int g[N];
int V[N],W[N];
int f[N];

int main(){
    cin >> n >> m;
    int v,w,s;
    for(int i = 0;i < n;i++){
        cin >> v >> w >> s;
        if(s == -1){
            for(int j = m;j >= v;j--)f[j] = max(f[j],f[j - v] + w);
        }else {
            if(s == 0){
                for(int j = v;j <= m;j++)f[j] = max(f[j],f[j - v] + w);
            } else{
                int k = 1;
                int cnt = 0;
                if(k <= s){
                    V[cnt] = k * v;
                    W[cnt++] = k * w;
                    s -= k;
                    k <<= 1;
                }
                if(s){
                    V[cnt] = s * v;
                    W[cnt++] = s * w;
                }
                for(int j = 0;j < cnt;j++)
                    for(int k = m;k >= V[j];k--){
                        f[k] = max(f[k],f[k - V[j]] + W[j]);
                    }
            }
        }
    }
    cout << f[m] << endl;
}