/*
 * 最长公共子序列
 *  f[i][j]：a数组的1~i b数组的1~j中，且b[j]结尾的最长上升公共子序列的集合，其值为长度最大的哪个公共子序列的长度
 *  这样，我们就剩下讨论a[i]，是否在其中即可
 *  f[i][j] = max(f[i - 1][j],f[i - 1][k] + 1) k代表b[j]上一个能取到最大长度的位置。
 *
 */
//TLE做法
/**
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

const int N = 3010;

int n,m;
int a[N],b[N];
int f[N][N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++)cin >> b[i];
    int res = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            f[i][j] = f[i - 1][j];//a[i]不包含
            //包含a[i]
            if(a[i] == b[j]){
                int maxv = 1;
                for(int k = 1;k < j;k++){
                    if(a[i] > b[k])maxv = max(maxv,f[i - 1][k] + 1);
                }
                f[i][j] = max(f[i][j],maxv);
            }
            res = max(res,f[i][j]);
        }
    }
    cout << res << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}
 */
 //优化
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

const int N = 3010;

int n,m;
int a[N],b[N];
int f[N][N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++)cin >> b[i];
    int res = 0;
    for(int i = 1;i <= n;i++){
        int maxv = 1;
        for(int j = 1;j <= n;j++){
            f[i][j] = f[i - 1][j];
            if(a[i] == b[j])f[i][j] = max(f[i][j],maxv);
            if(a[i] > b[j])maxv = max(maxv,f[i - 1][j] + 1);
            res = max(res,f[i][j]);
        }
    }
    cout << res << endl;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve();

    return 0;
}