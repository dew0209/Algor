//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n,m;
int f[N][N];
int v[N],w[N];
int way[N];

int main(){
    
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++){
        cin >> v[i] >> w[i];
    }
    for(int i = n;i >= 1;i--){
        for(int j = 1;j <= m;j++){
            f[i][j] = f[i + 1][j];
            if(j >= v[i]){
                f[i][j] = max(f[i][j],f[i + 1][j - v[i]] + w[i]);
            }
        }
    }
    int count = m;
    for(int i = 1;i <= n;i++){
        
        if(count >= v[i] && f[i][count] == f[i + 1][count - v[i]] + w[i]){
            cout << i << ' ';
            count -= v[i];
        }
    }
    return 0;
}