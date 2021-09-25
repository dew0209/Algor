/*
 * 能量石
 * 考虑相邻的两块：
 *      si  si+1
 *      1.先吃si --> ei + ei+1 - Li+1 * si
 *      2.先吃si+1 --> ei+1 + ei - Li * si+1
 *      --> 先吃 Li+1 / si+1 比值小的较好
 * f[i]：恰好花费时间i所能获取到的最大能量
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Stone{
    int s,e,l;
    bool operator < (Stone& w){
        return s * w.l < w.s * l;
    }
}stones[N];

int n,m;
int f[N];
int ans = 1;

void solve(){
    cin >> n;
    m = 0;
    for(int i = 1;i <= n;i++){
        int a,b,c;cin >> a >> b >> c;
        stones[i] = {a,b,c};
        m += a;
    }
    sort(stones + 1,stones + n + 1);
    memset(f,-0x3f,sizeof f);
    f[0] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= stones[i].s;j--){
            f[j] = max(f[j],f[j - stones[i].s] + max(0,stones[i].e - (j - stones[i].s) * stones[i].l));
        }
    }
    int res = 0;
    for(int i = 0;i <= m;i++){
        res = max(res,f[i]);
    }
    cout << "Case #" << ans++ << ": " << res << endl;
}

int main(){
    int T;cin >> T;
    while (T--)solve();

    return 0;
}