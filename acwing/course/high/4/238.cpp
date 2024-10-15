//并查集


/*
    d数组记录该节点到队头的距离，而S数组记录队大小，也就是连通块大小。
    abs(d[a] - d[b]) - 1就是两者之间的距离
        d[a] - d[b] = （a到队头距离） - （b到队头距离）。也就是ab之间距离

    合并：
        将a合并到b
            那么d[a]将表示到a到队头b的距离，该距离等于S[b];
            在后续的路径优化中，有 d[a] += d[p[a]]操作，会将a的后面点，更新成到新队头b的距离。

*/
#include <iostream>
#include <cstring> 
#include <algorithm>

using namespace std;

const int N = 30010;

int n,m;
int p[N];
int S[N];
int d[N];

int find(int u){
    if(p[u] != u){
        int t = find(p[u]);
        d[u] += d[p[u]];
        p[u] = t;
    }
    return p[u];
}

int main(){
    int m;
    scanf("%d",&m);
    for(int i = 1;i < N;i++){
        p[i] = i;
        S[i] = 1;
    }
    for(int t = 0;t < m;t++){
        char op[2];
        int i,j;
        scanf("%s",&op);
        scanf("%d%d",&i,&j);
        if(*op == 'M'){
            i = find(i);
            j = find(j);
            if(i != j){
                d[i] += S[j];
                S[j] += S[i];
                p[i] = j;
            }
        }else {
            int x = find(i);
            int y = find(j);
            if(x != y){
                puts("-1");
            }else {
                int res = max(0,abs(d[i] - d[j]) - 1);
                printf("%d\n",res);
            }
        }
    }
    return 0;
}