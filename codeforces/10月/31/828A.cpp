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

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,a,b;
int q[N];

int main(){
    cin >> n >> a >> b;
    int cb = 0;
    for(int i = 0;i < n;i++)cin >> q[i];
    int res = 0;
    for(int i = 0;i < n;i++){
        if(q[i] == 1){
            if(a){
                a--;
            }else if(b){
                b--;
                cb++;
            }else if(cb) {
                cb--;
            }else {
                res++;
            }
        }else {
            if(b){
                b--;
            }else res += 2;
        }
    }
    cout << res << endl;

    return 0;
}