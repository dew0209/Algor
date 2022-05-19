#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long LL;

using namespace std;

const int N = 200010;

LL n,x,m;
LL q[N];

int main(){
    cin >> n >> m >> x;
    for(int i = 0;i < n;i++){
        cin >> q[i];
    }
    sort(q,q + n);
    vector<LL> ans;
    for(int i = 0;i < n;i++){
        if(q[i + 1] - q[i] > x){
            LL diff = q[i + 1] - q[i];
            ans.push_back((q[i + 1] - q[i] + x - 1 ) / x - 1);
        }
    }
    
    LL res = ans.size() + 1;
    sort(ans.begin(),ans.end());
    for(int i = 0;i < ans.size();i++){
        if(m - ans[i] < 0)break;
        res--;
        m -= ans[i];
    }
    cout << res << endl;
}