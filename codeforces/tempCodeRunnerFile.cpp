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
    for(int i = 1;i <= n;i++)cin >> q[i];
    int st = 1,ed = n;
    int preCnt = 0,sufCnt = 0;
    while(q[st] % m == 0 && st <= n)st++,preCnt++;
    while(q[ed] % m == 0 && ed >= 1)ed--,sufCnt++;
    int res = n - preCnt - sufCnt;
    if(res < 0)res = -1;
    cout << res << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}