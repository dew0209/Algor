//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3010;

int n;
int f[N][N];
int a[N],b[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++)cin >> b[i];
    int res = 0;
    for(int i = 1;i <= n;i++){
        int maxv = 1;
        for(int j = 1;j <= n;j++){
            f[i][j] = f[i - 1][j];
            if(a[i] == b[j])f[i][j] = max(maxv,f[i][j]);
            if(a[i] > b[j])maxv = max(maxv,f[i - 1][j] + 1);
        }
    }
    
    for(int i = 1;i <= n;i++){
        res = max(res,f[n][i]);
    }
    cout << res << endl;
    return 0;
}