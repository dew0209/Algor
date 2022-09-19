#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,m,h;
int a[110],b[110];
int c[110][110];

int main(){
    cin >> n >> m >> h;    
    for(int i = 0;i < m;i++)cin >> b[i];
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(c[i][j]){
                cout << min(a[i],b[j]) << ' ';
            }else cout << 0 << ' ';
        }
        cout << endl;
    }
    return 0;
}