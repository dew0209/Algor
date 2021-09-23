/*
 * 登山
 *  按照景点顺序来参观
 *      1.不能连续浏览海拔相同的两个景点
 *      2.连续两个景点的海拔是呈下降的，之后的就不能上升了
 *  --->结果类似一个先上升后下降的形状，可以只存在一边的情况[这个视具体的题目题意而定]
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

const int N = 110;

int n,m;
int a[N];
int f[N],d[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++){
        f[i] = 1;
        for(int j = 1;j < i;j++){
            if(a[i] > a[j])f[i] = max(f[i],f[j] + 1);
        }
    }
    for(int i = n;i >= 1;i--){
        d[i] = 1;
        for(int j = n;j > i;j--){
            if(a[i] > a[j])d[i] = max(d[i],d[j] + 1);
        }
    }
    int res = 0;
    for(int i = 1;i <= n;i++)
        res = max(res,f[i] + d[i] - 1);
    cout << res << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}