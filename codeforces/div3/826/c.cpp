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

const int N = 1000010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
LL q[N];
LL s[N];

void solve(){
    cin >> n;
    LL sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
        sum += q[i];
        s[i] = q[i] + s[i - 1];
    }
    int ans = n;
    for(int len = 1;len <= min(n,2000);len++){
        //len是分了几个部分
        if(sum % len == 0){
            int x = sum / len;//每段的长度
            bool ok = true;//是否有这种情况
            int cnt = -1;
            int tmp = 1;
            int last = 0;
            for(int i = 1;i <= n;i++){
                if(s[i] == x * tmp){
                    tmp++;
                    cnt = max(cnt,i - last);
                    last = i;
                    //cout << cnt << "debug" << last << endl; 
                }
            }
            //cout << "tmp:" << tmp << endl;
            if(tmp == len + 1){
                ans = min(ans,cnt);
            }
        }
    }
    cout << ans;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}