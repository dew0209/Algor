//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n,m;
int f[N][N];
int v[N][N];
int way[N];

int main(){
    
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> v[i][j];
        }
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            for(int t = 0;t <= j;t++){
                f[i][j] = max(f[i][j],f[i - 1][j - t] + v[i][t]);
            }
        }
    }
    int res = f[n][m];
    cout << res << endl;
    
    int count = m;
    
    for(int i = n;i > 0;i--){
        for(int j = 0;j <= count;j++){
            if(f[i][count] == f[i - 1][count - j] + v[i][j]){
                way[i] = j;
                count -= j;
                break;
            }
        }
    }
    for(int i = 1;i <= n;i++)cout << i << ' ' << way[i] << endl;
    
    return 0;
}