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

int n,m;
int q[N];

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++)cin >> q[i];
    int minv = INF;
    int maxv = -INF;
    for(int i = 0;i < n;i++){
        minv = min(minv,q[i]);
        maxv = max(maxv,q[i]);
    }
    if(m == 1){
        cout << minv << endl;;
    }else if(m == 2){
        cout << max(q[0],q[n - 1]) << endl;
    }else {
        cout << maxv << endl;
    }
    
    return 0;
}