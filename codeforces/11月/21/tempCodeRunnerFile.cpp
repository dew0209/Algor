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

int n,m,k;

int main(){
    cin >> n >> k;
    vector<pair<double,int>> cnt;
    for(int i = 0;i < n;i++){
        int l,r,sum;cin >> l >> r >> sum;
        double dist = sqrt(l * l + r * r);
        //cout << dist << "--------" << endl;
        cnt.push_back({dist,sum});
    }
    sort(cnt.begin(),cnt.end());
    double ans = 0;
    for(auto c : cnt){
        if(k <= 1e6){
            k += c.se;
            ans = c.fi;
        }else break;
    }
    //cout << ans << endl;
    if(k < 1e6){
        ans = -1;
    }
    printf("%.6lf\n",ans);
}