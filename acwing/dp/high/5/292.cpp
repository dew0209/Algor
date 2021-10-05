#include <cstdio>
#include <vector>
#include <iostream>

#define pb  push_back
#define fi first
#define se second
#define rep1(a,b,c) for(int i = a;i < b;++c)
#define rep2(a,b,c) for(int i = a;i <= b;++c)

using namespace std;

typedef long long LL;
typedef vector<int> VI;

const int N = 110,M = 1 << 12,MOD18 = 1e8;

//快读
template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

int n,m;
int g[N];//用二进制存储地图
int f[2][M][M];
VI st;
int sum[M];

bool check(int u){
    rep1(0,m - 1,i)if((u >> i & 1) && ((u >> i + 1 & 1) || (u >> i + 2 & 1)))return false;
    return true;
}

int get_tot(int u){
    int res = 0;
    while (u)res++,u -= u & -u;
    return res;
}

int main(){
    read(n), read(m);
    for(int i = 1;i <= n;i++){
        char c[N];
        scanf("%s",c);
        for(int j = 0;j < m;j++){
            g[i] += (c[j] == 'H') << j;
        }
        //printf("%d\n",g[i]);
    }
    //处理合法的状态
    rep1(0,1 << m,i)if(check(i))st.pb(i),sum[i] = get_tot(i);

    for(int i = 1;i <= n + 2;i++){
        for(int j = 0;j < st.size();j++){
            //if(st[j] & g[i])continue;
            for(int k = 0;k < st.size();k++){
                //if(st[k] & g[i - 1])continue;
                for(int u = 0;u < st.size();u++){
                    int a = st[j],b = st[k],c = st[u];
                    if((g[i] & a) || (g[i - 1] & b))continue;
                    if((a & b) == 0 && (a & c) == 0)
                        f[i & 1][a][b] = max(f[i & 1][a][b],f[i - 1 & 1][b][c] + sum[a]);
                }
            }
        }
    }
    printf("%d\n",f[n + 2 & 1][0][0]);

    return 0;
}