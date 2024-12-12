//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n,m,k;
int f[N][N];

int main(){
    cin >> m >> n >> k;
    
    memset(f,0x3f,sizeof f);
    f[0][0] = 0;
    int a,b,c;
    for(int i = 1;i <= k;i++){
        cin >> a >> b >> c;
        for(int j = m;j >= 0;j--){
            for(int t = n;t >= 0;t--){
                f[j][t] = min(f[j][t],f[max(j - a,0)][max(t - b,0)] + c);
            }
        }
    }
    cout << f[m][n] << endl;
    return 0;
}