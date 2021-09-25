/*
 * 分组背包 并且需要求具体的方案
 * int res = f[n][m]
 *
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30;

int n,m;
int path[N][N];
int w[N][N];
int f[N][N];
int way[N];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)cin >> w[i][j];
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= 0;j--){
            for(int k = 0;k <= j;k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
            }
        }
    }
    cout << f[n][m] << endl;
    int k = m;
    //求具体的方案
    for(int i = n;i >= 1;i--){
        for(int j = 1;j <= k;j++){
            if(f[i][k] == f[i - 1][k - j] + w[i][j]){
                way[i] = j;
                k -= j;
                break;
            }
        }
    }
    for(int i = 1;i <= n;i++)cout << i << ' ' << way[i] << endl;

    return 0;
}