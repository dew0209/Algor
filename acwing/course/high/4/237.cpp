//并查集

/*
    思路：离散化 + 并查集
        先将想等的数据集中到一个连通块里面，再来判断不相等的是否在一个连通块即可。
        由于值范围比较大，但是数据最多为1e5个，所以要进行离散化。
*/


#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N = 200010;

int n;
int p[N];
int q[N][2];
int idx = 0;
map<int,int> cnt;
int lsh = 1;

int find(int u){
    if(p[u] != u)p[u] = find(p[u]);
    return p[u];
}

int query(int u){
    if(cnt.count(u)){
        return cnt[u];
    }
    cnt[u] = lsh++;
    return cnt[u];
}

void solve(){
    
    idx = 0;
    scanf("%d",&n);
    
    cnt.clear();
    
    lsh = 1;
    
    for(int i = 1;i <= N;i++){
        p[i] = i;
    }
    
    for(int t = 0;t < n;t++){
        int i,j,e;
        scanf("%d%d%d",&i,&j,&e);
        if(e == 0){
            q[idx][0] = i;
            q[idx++][1] = j;
        }else {
            i = find(query(i));
            j = find(query(j));
            p[i] = j;
        }
    }
    for(int i = 0;i < idx;i++){
        int a = q[i][0];
        int b = q[i][1];
        a = find(query(a));
        b = find(query(b));
        if(a == b){
            printf("NO\n");
            return ;
        }
        
    }
    
    printf("YES\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}