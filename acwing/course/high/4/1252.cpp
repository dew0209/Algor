//并查集

/*
思路：对搭配要进行处理，同一个搭配捆绑销售并且重新计算价值和价格（使用并查集）。
        计算最大价值使用01背包即可
        并查集 + 01背包
*/


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n,m,W;
int p[N];
int w[N];
int price[N];
int f[N];


int find(int u){
    if(p[u] != u)p[u] = find(p[u]);
    return p[u];
}

int main(){
    scanf("%d%d%d",&n,&m,&W);
    
    for(int i = 1;i <= n;i++)p[i] = i;
    
    for(int i = 1;i <= n;i++){
        int c,d;
        scanf("%d%d",&c,&d);
        price[i] = c;
        w[i] = d;
    }
    
    //搭配
    for(int i = 0;i < m;i++){
        
        int u,v;
        scanf("%d%d",&u,&v);
        
        u = find(u);
        v = find(v);
        if(u != v){
            p[u] = v;
            w[v] += w[u];
            price[v] += price[u];
        }
    }
    
    vector<int> goods;
    
    for(int i = 1;i <= n;i++){
        if(p[i] == i){
            goods.push_back(i);
        }
    }
    int len = goods.size();
    for(int i = 0;i < len;i++){
        for(int j = W;j >= price[goods[i]];j--){
            f[j] = max(f[j],f[j - price[goods[i]]] + w[goods[i]]);
        }
    }
    printf("%d\n",f[W]);
    return 0;
}