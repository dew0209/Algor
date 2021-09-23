/*
 * 拦截导弹
 *   1.一个最长的下降子序列
 *   2.贪心
 *      思路：
 *          以 389 207 155 300 299 170 158 65 为例
 *          遍历到第一个点，开一个 导弹:389
 *          遍历到第二个点，207，可以接到389后面
 *          ...
 *          遍历到第四个点，300，开一个新导弹
 *          ...
 *
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <deque>
#include <queue>
#include <set>

using namespace std;

#define fi first
#define se second

typedef long long LL;
typedef pair<int,int> PII;

const int N = 1010;

int n,m;
int a[N];
int f[N];

void solve(){
    while(cin >> a[n++]);
    int res = 0;
    for(int i = 0;i < n;i++){
        f[i] = 1;
        for(int j = 0;j < i;j++){
            if(a[i] <= a[j])f[i] = max(f[i],f[j] + 1);
        }
        res = max(res,f[i]);
    }
    cout << res << endl;

}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}