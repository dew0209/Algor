/*
 * 跑两次dp解决方格取数问题
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
        cout << x << ' ' << y << endl;
    }
    memset(f,0,sizeof f);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + g[i][j];
        }
    }
    cout << res + f[n][n] << endl;
}

//int main(){
//    int T = 1;//cin >> T;
//    while(T--)solve();
//    return 0;
//}