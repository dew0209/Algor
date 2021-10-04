/**
 * 大盗阿福
 * 设f[i][0/1]：代表从[1,i]中进行选择的所有方案，0代表不选第i个，1代表选第i个。其值为所有方案中最大的值
 * f[i][0] = max(f[i - 1][1],f[i - 1][0])
 * f[i][1] = f[i - 1][0] + a[i]
 * 模拟案例：
 *      1
 *      4
 *      10 7 6 14
 *      f数组：
 *      不盗取这个店    盗取这个店
 *      0              10         10
 *      10             7           7   f[2][1]为7，注意：很多人往往很迷惑，以为a[1-i]都被选取了，一定要摈弃这种思想
 *      10             16          6   16 = 盗取这个店 + 不盗取上一个店 + 盗取上上个店，注意：在计算f[i][1]的时候，一定要保证f[i - 1][0]是最优的，这一点在状态的初始化的时候，总是被人误解，虽然有时候，初始化多了一些数答案不受影响，但是状态的含义就不一样了
 *      16             24         14   24 = 盗取这个店(14) + 不盗取上一个店 + 不盗取上上个店 + 盗取上上上个店(10)  --> 有时候，间隔选不一定最大，如果选取了14，很多人会自然的选择7，这是没有感性的认知
 *
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

const int N = 100010;

int n,m;
int f[N][2];

void solve(){
    cin >> n;
    int c;
    for(int i = 1;i <= n;i++){
        cin >> c;
        //不抢
        f[i][0] = max(f[i - 1][0],f[i - 1][1]);
        //选
        f[i][1] = f[i - 1][0] + c;
        cout << f[i][0] << ' ' << f[i][1] << endl;
    }
    cout << max(f[n][0],f[n][1]) << endl;
}

int main(){
    int T = 1;cin >> T;
    while(T--)solve();

    return 0;
}