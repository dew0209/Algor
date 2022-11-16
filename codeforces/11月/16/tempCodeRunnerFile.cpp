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

const int N = 1010;

int n,m;
int q[N];

int main(){
    cin >> n >> m;
    int ans = 0;
    for(int tr = 1;tr <= n;tr++){
        int lc = 0;
        for(int td = 1;td <= m;td++){
            int c;cin >> c;
            if(c){
                ans += tr - q[td] - 1;
                ans += td - lc - 1;
                q[td] = tr;
                lc = td;
            }else {
                if(q[td])ans++;
                if(lc)ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}