//dp

//区间dp


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 40;

int n;
int g[N][N];
int f[N][N];
int w[N];

void dfs(int l,int r){
    
    if(l > r)return ;
    
    int k = g[l][r];
    cout << k << ' ';
    dfs(l,k - 1);
    dfs(k + 1,r);
}

int main(){
    
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> w[i];
    }
    
    for(int i = 1;i <= n;i++){
        f[i][i] = w[i];
        g[i][i] = i;
    }
    
    for(int len = 2;len <= n;len++){
        for(int l = 1;l + len - 1 <= n;l++){
            int r = l + len - 1;
            for(int k = l;k <= r;k++){//w[k]为根节点
                int vl = l == k ? 1 : f[l][k - 1];
                int vr = r == k ? 1 : f[k + 1][r];
                int source = vl * vr + w[k];
                if(source > f[l][r]){
                    f[l][r] = source;
                    g[l][r] = k;
                }
            }
        }
    }
    
    cout << f[1][n] << endl;
    
    dfs(1,n);
        
    return 0;
}