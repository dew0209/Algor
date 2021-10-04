/*
 * 1064 小国王
 *
 * 八连通：
 *    o o o
 *    0 x o
 *    o o o
 * 设第i行的状态为x，第i - 1行的状态为j
 * 条件:
 *    ①：x,y放置的地方的相邻的点，不能在放置
 *    ②：x & y 为0
 *    ③：x | y 相邻的点不能有冲突
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define pb(x) push_back(x);

using namespace std;

const int N = 12,M = 1 << N,K = 110;

typedef long long LL;
typedef vector<int> VI;

int n,m;
LL f[N][M][K];
VI state;
VI head[M];
int cnt[M];

int lowbit(int u){
    int res = 0;
    while(u){
        res++;
        u -= u & -u;
    }
    return res;
}

bool check(int u){
    for(int i = 0;i < n;i++){
        if((u >> i & 1) && (u >> i + 1 & 1))return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    //删选条件①
    for(int i = 0;i < 1<<n;i++){
        if(check(i)){
            state.pb(i);
            cnt[i] = lowbit(i);
        }
    }
    int ans = state.size();
    for(int i = 0;i < ans;i++){
        for(int j = 0;j < ans;j++){
            int a = state[i],b = state[j];
            //删选条件②和③
            if((a & b) == 0 && (check(a | b))){
                head[i].pb(j);
            }
        }
    }
    f[0][0][0] = 1;
    for(int i = 1;i <= n + 1;i++){
        for(int j = 0;j < ans;j++){//符合的状态的个数
            for(int k = 0;k <= m;k++){
                for(int b : head[j]){//该状态相邻的符合的子状态
                    int c = cnt[state[j]];
                    if(k >= c)f[i][j][k] += f[i - 1][b][k - c];
                }
            }
        }
    }
    cout << f[n + 1][0][m] << endl;

    return 0;
}