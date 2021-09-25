/*
 * 有依赖的背包问题 [也是十分的难想，原地自闭型题目]
 * 设f[u][j]：以u为根节点的树中选择，体积<=j的所有选法
 * 对于每一个子树，我们可以选择或者不选，但是不清楚怎么选，这很麻烦，不如换个思路，给子树分配体积
 * f[u][j] = max(f[t][k] + f[u][j - k]);
 * 每个子树，相当于一个分组，一个分组背包求解问题
 * 5 7
 * 2 3 -1
 * 2 2 1
 * 3 5 1
 * 4 7 2
 * 3 6 2
 *
 * 每轮的f数组
 *  1 2 3 4 5 6 7
 *
 *  0 0 0 0 0 0 0
 *  0 0 0 0 0 0 0
 *  0 0 5 5 5 5 5
 *  0 0 0 0 0 0 0
 *  0 0 0 0 0 0 0
 *  debug3
 *  0 0 5 5 5 0 0
 *  0 0 0 0 0 0 0
 *  0 0 5 5 5 5 5
 *  0 0 0 0 0 0 0
 *  0 0 6 6 6 6 6
 *  debug5
 *  0 0 5 5 5 0 0
 *  0 0 6 6 6 0 0
 *  0 0 5 5 5 5 5
 *  0 0 0 7 7 7 7
 *  0 0 6 6 6 6 6
 *  debug4
 *  0 0 5 5 5 0 0
 *  0 2 2 2 8 9 9
 *  0 0 5 5 5 5 5
 *  0 0 0 7 7 7 7
 *  0 0 6 6 6 6 6
 *  debug2
 *  0 3 3 5 8 8 11
 *  0 2 2 2 8 9 9
 *  0 0 5 5 5 5 5
 *  0 0 0 7 7 7 7
 *  0 0 6 6 6 6 6
 *  debug1
 *
 *  有依赖的背包问题：dp的顺序是随意的，不确定的，根据题目而来
 *
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int n,m;
int f[N][N];
int w[N],v[N];
int h[N],e[N],ne[N],idx;

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void dfs(int u){
    for(int i = h[u];~i;i = ne[i]){
        int t = e[i];
        dfs(t);
        for(int j = m - v[u];j >= 0;j--){
            //分组背包
            for(int k = 0;k <= j;k++){
                f[u][j] = max(f[u][j],f[t][k] + f[u][j - k]);
            }
        }
    }
    for(int j = m;j >= v[u];j--)f[u][j] = f[u][j - v[u]] + w[u];
    for(int j = v[u] - 1;j >= 0;j--)f[u][j] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "debug" << u << endl;
}

int main(){
    cin >> n >> m;
    int root = -1;
    memset(h,-1,sizeof h);
    for(int i = 1;i <= n;i++){
        int a,b,c;cin >> a >> b >> c;
        v[i] = a;
        w[i] = b;
        if(c == -1)root = i;
        else add(c,i);
    }
    dfs(root);

    cout << f[root][m] << endl;

    return 0;
}