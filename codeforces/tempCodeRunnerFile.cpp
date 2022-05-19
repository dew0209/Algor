#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n,x,m;
int q[N];

int main(){
    cin >> n >> m >> x;
    for(int i = 0;i < n;i++){
        cin >> q[i];
    }
    sort(q,q + n);
    vector<int> ans;
    for(int i = 0;i < n;i++){
        if(q[i + 1] - q[i] > x){
            int diff = q[i + 1] - q[i];
            ans.push_back((q[i + 1] - q[i] + x - 1 ) / x - 1);
            //cout << i << " debug " << q[i + 1] - q[i] << " tun " << x <<endl;
        }
    }
    // for(int i = 0;i < ans.size();i++){
    //     cout << ans[i] << "++";
    // }
    // cout << endl;
    int res = ans.size() + 1;
    sort(ans.begin(),ans.end());
    for(int i = 0;i < ans.size();i++){
        if(m - ans[i] < 0)break;
        res--;
        m -= ans[i];
    }
    cout << res << endl;
}