#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define fi first
#define se second

typedef long long LL;

using namespace std;

int n,m;

void solve(){
    cin >> n;
    vector<pair<int,int>> cnt(n,{0,0});
    for(int i = 0;i < n;i++)cin >> cnt[i].fi;
    for(int i = 0;i < n;i++)cin >> cnt[i].se;
    vector<pair<int,int>> p(cnt);
    sort(cnt.begin(),cnt.end());
    bool ok = false;
    for(int i = 0;i < n - 1;i++){
        if(cnt[i].fi > cnt[i + 1].fi || cnt[i].se > cnt[i + 1].se){
            ok = true;
            break;
        }
    }
    if(ok)cout << "-1" << endl;
    else {
        //检查答案
        vector<pair<int,int>> ans;
        for(int i = 0;i < n;i++){
            if(cnt[i].fi != p[i].fi || cnt[i].se != p[i].se){
                for(int j = i + 1;j < n;j++){
                    if(cnt[i].fi == p[j].fi && cnt[i].se == p[j].se){
                        ans.push_back({i + 1,j + 1});
                        swap(p[i],p[j]);
                        break;
                    }
                }
            }
        }
        cout << ans.size() << endl;
        for(int i = 0;i < ans.size();i++){
            cout << ans[i].fi << ' ' << ans[i].se << endl;
        }
    }

}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}