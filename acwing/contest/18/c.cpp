#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010,M = N * 2;

int n;
int h[N],e[M],ne[M],idx;
int ans;

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

int dfs(int u,int fa){
    int d = 1;
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        if(j == fa)continue;
        int cnt = dfs(j,u);
        if(cnt % 2 == 0){
            ans++;
        }else {
            d += cnt;
        }
    }
    return d;
}

int main(){
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i = 1;i < n;i++){
        int a,b;cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    int res = dfs(1,-1);
    if(res % 2 == 1)cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}