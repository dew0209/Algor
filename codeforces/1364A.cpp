#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int N = 200010;

int n,m;
int q[N];

void solve(){
    cin >> n >> m;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
        sum += q[i];
    }
    int st = 1,ed = n;
    int preCnt = 1,sufCnt = 1;
    while(q[st] % m == 0 && st <= n)st++,preCnt++;
    while(q[ed] % m == 0 && ed >= 1)ed--,sufCnt++;
    
    int res = n - preCnt;
    int ans = n - sufCnt;
    res = max(res,ans);
    if(res < 0)res = -1;
    if(sum % m)res = n;
    cout << res << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}