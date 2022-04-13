//https://codeforces.com/problemset/problem/1399/C

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n,m;
int a[N];
int cnt[N];

void solve(){
    cin >> n;
    memset(cnt,0,sizeof cnt);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int res = 0;
    for(int i = 1;i <= 102;i++){
        int ans = 0;
        //cout << "run" << endl;
        for(int j = 1;j < i;j++){
            if(i - j < j)break;
            //cout << "debug" << endl;
            if(i - j != j){
                ans += min(cnt[j],cnt[i - j]);
            }else {
                ans += cnt[j] / 2;
            }
        }
        res = max(res,ans);
    }
    cout << res << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}