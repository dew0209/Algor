#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define fi first
#define se second

typedef long long LL;

using namespace std;

const int N = 100010;

int n,m;


int main(){
    cin >> n >> m;
    vector<pair<int,int>> res;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        res.push_back({c,i + 1});
    }
    sort(res.begin(),res.end());
    vector<int> ans;
    int count = 0;
    for(int i = n - 1;i >= n - m;i--){
        count += res[i].fi;
        ans.push_back(res[i].se);
    }
    cout << count << endl;
    sort(ans.begin(),ans.end());
    //ans.push_back(n + 1);
    if(m == 1){
        cout << n << endl;
        return 0;
    }
    for(int i = 0;i < ans.size();i++){
        if(i == ans.size() - 1){
            cout << n - ans[i - 1];
            break;
        }
        if(i != 0)
        cout << ans[i] - ans[i - 1] << ' ';
        else cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}