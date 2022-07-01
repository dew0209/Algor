//https://codeforces.com/contest/1355/problem/B
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n;

void solve(){
    cin >> n;
    vector<int> ans(n);
    for(int i = 0;i < n;i++){
        cin >> ans[i];
    }
    sort(ans.begin(),ans.end());
    int res = 0;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        //cout << ans[i] << " debug " << endl;
        if(++cnt == ans[i]){
            res++;
            cnt = 0;
        }
    }
    cout << res;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}