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
int q[N];
int ans;

void dfs(int l,int r){
    if(abs(r - l) <= 1){
        if(q[l] > q[r]){
            ans++;
            swap(q[l],q[r]);
        }
        return;
    }
    int mid = l + r >> 1;
    dfs(l,mid);
    dfs(mid + 1,r);
    //左右边都是有序的
    if(q[mid] > q[mid + 1]){
        ans++;
        for(int i = l,j = mid + 1;i <= mid;i++,j++){
            swap(q[i],q[j]);
        }
    }
}

void solve(){
    cin >> n;
    ans = 0;
    for(int i = 1;i <= n;i++)cin >> q[i];
    dfs(1,n);
    //检查
    for(int i = 1;i < n;i++){
        if(q[i] > q[i + 1]){
            ans = -1;
        }
    }
    cout << ans;
}


int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}