/*
 * 跑两次dp解决方格取数问题
 *  不行，错误的解决方案
 *  以
 *      4
 *      1 1 9
 *      2 2 9
 *      3 3 9
 *      4 4 9
 *      4 2 1
 *      1 3 7
 *      0 0 0
 *  构建的图为：
 *      9 0 7 0
 *      0 9 0 0
 *      0 0 9 0
 *      0 1 0 9
 *  最大值为全部选44，但是跑出来却是43
 *  两条一起跑，可以枚举所有可能，而两次分开跑，不能枚举所有。
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <deque>
#include <queue>
#include <set>

using namespace std;

#define fi first
#define se second

typedef long long LL;
typedef pair<int,int> PII;

const int N = 110;

int n,m;
int g[N][N];
int f[N][N];
PII path[N][N];

void solve(){
    cin >> n;
    int a,b,c;
    while(cin >> a >> b >> c,a || b || c)g[a][b] = c;
    //第一次dp
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            f[i][j] = max(f[i - 1][j],f[i][j - 1]) + g[i][j];
            if(f[i - 1][j] > f[i][j - 1]){
                path[i][j] = {i - 1,j};
            }else if(f[i - 1][j] == f[i][j - 1]){
                if(i - 1 >= 1)path[i][j] = {i - 1,j};
                else path[i][j] = {i,j - 1};
            }else {
                path[i][j] = {i,j - 1};
            }
        }
    }
    int res = f[n][n];
    //处理点
    int x = n,y = n;
    g[1][1] = 0;
    g[n][n] = 0;
    //cout << res << endl;
    while(x != 1 || y != 1){
        //cout << x << ' ' << y << endl;
        g[x][y] = 0;
        PII t = path[x][y];
        x = t.fi;
        y = t.se;
        //if(x < 1 || y < 1)break;
    }
    memset(f,0,sizeof f);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + g[i][j];
        }
    }
    cout << res + f[n][n] << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();
    return 0;
}