//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50010,M = N * 2;

int n;
int h[N],e[M],ne[M],idx;
int sum[N];
int st[N];
int ans;

void add(int a,int b){
    
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u){
    
    st[u] = true;
    
    int d1 = 0,d2 = 0;
    
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        if(!st[j]){
            int d = dfs(j) + 1;
            if(d > d1){
                d2 = d1;d1 = d;
            }else if(d > d2){
                d2 = d;
            }
        }
    }
    ans = max(ans,d1 + d2);
    return d1;
    
}

int main(){
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i = 1;i <= n;i++){
        for(int j = 2;j <= n / i;j++){
            sum[i * j] += i;
        }
    }
    
    for(int i = 2;i <= n;i++){
        if(i > sum[i]){
            add(sum[i],i);
        }
    }
    
    for(int i = 1;i <= n;i++){
        if(!st[i]){
            dfs(i);
        }
    }
    
    cout << ans << endl;
    
    return 0;
    
}