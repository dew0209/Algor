#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

using namespace std;

const int N = 300010,MOD = 1e9 + 7;

int n,m;
int q[N];
LL suf[N];
LL pre[N];

void solve(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)scanf("%d",&q[i]);
    int ok = 0;
    for(int i = 1;i <= n;i++){
        pre[i] = q[i] + pre[i - 1];
        if(i != n && pre[i] <= 0){
            ok = 1;
        }
    }
    suf[n + 1] = 0;
    for(int i = n;i >= 1;i--){
        suf[i] = q[i] + suf[i + 1];
        if(i != 1 && suf[i] <= 0){
            ok = 1;
        }
    }
    if(pre[n] <= 0 || ok){
        printf("No");
    }else {
        printf("Yes");
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}