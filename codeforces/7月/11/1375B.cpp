#include <iostream>
#include <cstring>
#include <algorithm>
#include <numeric>

typedef long long LL;

const int N = 310;

using namespace std;

int n,m;
int a[N][N];

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            a[i][j] = 0;
            if(i - 1 >= 1)a[i][j]++;
            if(i + 1 <= n)a[i][j]++;
            if(j - 1 >= 1)a[i][j]++;
            if(j + 1 <= m)a[i][j]++;
        }
    }
    bool ok = true;
    //if(n == 0 || m == 0)ok = false;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            int x;cin >> x;
            if(x && a[i][j] < x){
                ok = false;
            }
        }
    }
    if(ok){
        cout << "YES" << endl;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }else {
        cout << "NO" << endl;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}