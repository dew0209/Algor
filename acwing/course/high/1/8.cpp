//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n,v,m;
int f[N][N];


int main(){
    cin >> n >> v >> m;
    int a,b,c;
    for(int i = 1;i <= n;i++){
        cin >> a >> b >> c;
        for(int j = v;j >= a;j--){
            for(int t = m;t >= b;t--){
                f[j][t] = max(f[j][t],f[j - a][t - b] + c);
            }
        }
    }
    cout << f[v][m] << endl;
    return 0;
}