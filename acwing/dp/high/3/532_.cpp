/*
 * 货币系统：
 *      求一个货币系统的最简化，即两个货币系统是等价的，能够表示的货币是一样的
 *   1.先把货币排序
 *   2.遍历，如果该货币不能由直接的货币表示，则选择，否则不选
 *
 *   A集合中不能被其他数组成的数一定会在B集合中出现。
 *      设x 属于 A ，且不能由其它 A 中元素表示出来
 *      假设x 不属于 B，那么B肯定存在至少一个不属于A但是属于B的数，且这个数不能被A组合出来不然就可以省去，这和等价矛盾
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
bool st[N];
int a[N];

void solve(){
    cin >> n;
    int ans = 0;
    for(int i = 0;i < n;i++)cin >> a[i];
    sort(a,a + n);
    for(int i = 0;i < n;i++){
        if(!st[a[i]])ans++;
        for(int j = a[i];j <= 25000;j++){
            if(st[j - a[i]])st[j] = true;
        }
    }
    cout << ans << endl;
}

int main(){
    int T = 1;cin >> T;
    while(T--)solve();

    return 0;
}