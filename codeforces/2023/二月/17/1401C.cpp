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

const int N = 100010,MOD = 1e9 + 7;

int n;
int q[N];
int p[N];

void solve(){
    scanf("%d",&n);
    int minv = MOD;
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
        p[i] = q[i];
        minv = min(minv,q[i]);
    }
    sort(q,q + n);
    int ok = 1;
    for(int i = 0;i < n;i++){
        if(p[i] != q[i]){
            if(p[i] % minv != 0){
                ok = 0;
                break;
            }
        }
    }
    if(ok){
        printf("Yes");
    }else {
        printf("No");
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}