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

const int N = 200010,MOD = 1e9 + 7;

int n,m;
int q[N],p[N],cnt[N];

int get(int l,int r,int target){
    while(l < r){
        int mid = l + r + 1>> 1;
        if(q[mid] <= target){
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    return l;
}

int main(){
    vector<int> st;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
    }
    for(int i = 0;i < m;i++){
        scanf("%d",&p[i]);
    }
    sort(q + 1,q + n + 1);
    for(int i = 0;i < m;i++){
        printf("%d ",get(0,n,p[i]));
    }
    return 0;
}