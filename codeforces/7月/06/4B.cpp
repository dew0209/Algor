#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int main(){
    int d,sumTime;cin >> d >> sumTime;
    vector<pair<int,int>> res;
    vector<int> ans;
    int left = 0,right = 0;
    for(int i = 0;i < d;i++){
        int l,r;cin >> l >> r;
        left += l;
        right += r;
        res.push_back({r - l,i});
        ans.push_back(l);
    }
    if(sumTime < left || sumTime > right){
        cout << "NO" << endl;
    }else {

        for(int i = 0;i < d;i++){
            sumTime -= ans[i];
        }
        int idx = d - 1;
        sort(res.begin(),res.end());
        while (idx >= 0 && sumTime){
            if(res[idx].first >= sumTime){
                res[idx].first -= sumTime;
                ans[res[idx].second] += sumTime;
                sumTime = 0;
                idx--;
            }else {
                ans[res[idx].second] += res[idx].first;
                sumTime -= res[idx].first;
                idx--;
            }
            //cout << "YES" << sumTime << "--" << idx << endl;
        }
        cout << "YES" << endl;
        for(int i = 0;i < d;i++){
            cout << ans[i] << ' ';
        }
    }
}