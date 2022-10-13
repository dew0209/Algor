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
int idx[1010];

int gcb(int a,int b){
    return b ? gcb(b,a%b):a;
}

void solve(){
    memset(idx,-1,sizeof idx);
    cin >> n;
    int res = -1;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        idx[c] = max(idx[c],i + 1);
    }
    for(int i = 1;i <= 1000;i++){
        for(int j = 1;j <= 1000;j++){
            if(gcb(i,j) == 1){
                if(idx[i] != -1 && idx[j] != -1){
                    res = max(res,idx[i] + idx[j]);
                }
            }
        }
    }
    cout << res;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}