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

void solve(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++)scanf("%d",&q[i]);
    int l = 0,r = 0;
    int maxv = 0,idx = 1;
    int tol = 0;
    for(int i = 1;i < n;i++){
        if(r - 1 >= 0 && q[r] > q[r - 1] && q[r] > q[i]){
            tol++;
        }
        r = i;
        if(r - l + 1 > m){
            if(l + 2 <= r && q[l + 1] > q[l] && q[l + 1] > q[l + 2]){
                tol--;
            }
            l++;
        }
        if(tol > maxv){
            maxv = tol;
            idx = l + 1;
        }
    }
    printf("%d %d",maxv + 1,idx);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}