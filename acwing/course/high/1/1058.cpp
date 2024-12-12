//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010,M = 110;


int n,m;
int f[N][3];
int g[N];

int main(){
    
    cin >> n ;
    
    for(int i = 1;i <= n;i++){
        cin >> g[i];
    }
    memset(f,-0x3f,sizeof f);
    
    for(int i = 0;i <= n;i++){
        f[i][2] = 0;
    }
    
    for(int i = 1;i <= n;i++){
        f[i][0] = max(f[i - 1][0],f[i - 1][2] - g[i]);
        f[i][1] = f[i - 1][0] + g[i];
        f[i][2] = max(f[i - 1][2],f[i - 1][1]);
    }
    
    cout << max(f[n][1],f[n][2]) << endl;
    
    return 0;
}