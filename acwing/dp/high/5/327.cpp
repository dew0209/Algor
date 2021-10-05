#include <cstdio>
#include <vector>

#define pb  push_back
#define fi first
#define se second

using namespace std;

typedef long long LL;
typedef vector<int> VI;

const int N = 15,M = 1 << 12,MOD18 = 1e8;

//快读
template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

int n,m;

int g[N];
int f[N][M];
VI state;//存储所有合法的状态

//检查状态的合法性
bool check(int u){
    for(int i = 0;i < m;i++){
        if(((u >> i) & 1) && ((u >> (i + 1)) & 1))return false;
    }
    return true;
}

int main(){
    read(n), read(m);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < m;j++){
            //0是不能种植的土地，这里为了方便，将1设置为不能种植的土地
            int c;read(c);
            g[i] += (!c << j);//取反进行+操作，用g[i]存储每一行土地的肥沃状态
        }
    }
    //一行有m个小方格。所以i < 1 << m即可
    for(int i = 0;i < 1 << m;i++)if(check(i))state.pb(i);

    //state得到了所有的合法状态
    f[0][0] = 1;
    for(int i = 1;i <= n + 1;i++){
        for(int j = 0;j < state.size();j++){
            int a = state[j];
            if((g[i] & a) == 0){//没有种在不育的土地上
                for(int k = 0;k < state.size();k++){
                    int b = state[k];
                    if((a & b) == 0)f[i][a] = (f[i][a] + f[i - 1][b]) % MOD18;
                }
            }
        }
    }
    printf("%d",f[n + 1][0]);

    return 0;
}