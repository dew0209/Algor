#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 1000010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
int q[N];

void solve(){
    cin >> n;
    q[1] = n;
    q[2] = n - 1;
    for(int i = 3;i <= n;i++){
        q[i] = i - 2;
    }
    bool ok = true;
    for(int i = 2;i < n;i++){
        if((abs(q[i] - q[i - 1]) <= 1 || abs(q[i] - q[i + 1]) <= 1) && q[i] != i){

        }else {
            ok = false;
            break;
        }
    }
    if(!ok){
        cout << -1;
    }else {
        for(int i = 1;i <= n;i++){
            cout << q[i] << ' ';
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--)solve(),puts("");
    return 0;
}