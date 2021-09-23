/*
 * 怪盗基德的滑翔翼
 *      最长上升子序列模型
 *   8
 *   300 207 155 299 298 170 158 65
 *   6
 *   300 299 298 170 158 65
 *   中途不能改变方向：
 *          选择一个起点，以i为起点，只能一直向左走或者向右走，不能向右走又向左走，同样，也不能向左走又向右走。这是不符合题意的。
 *   解决：
 *      可以从前往后走一边最长上升子序列，然后从后往前在做一遍最长上升子序列模型即可
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
        for(int j = n;j > i;j--){
            if(a[i] > a[j])d[i] = max(d[i],d[j] + 1);
        }
    }
    int maxv = 0;
    for(int i = 1;i <= n;i++)
        maxv = max(f[i],d[i]);
    cout << maxv << endl;
}

int main(){
    int T = 1;cin >> T;
    while(T--)solve();

    return 0;
}