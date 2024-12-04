//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int g[N][N];
int f[N][N];

int main(){
    cin >> n;
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> g[i][j];
        }
    }
    
    memset(f,0x3f,sizeof f);
    f[0][1] = 0;
    f[1][0] = 0;
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            f[i][j] = min(f[i - 1][j],f[i][j - 1]) + g[i][j];
        }
    }
    cout << f[n][n] << endl;
    return 0;
}