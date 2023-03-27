#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,LL> PIL;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;

const int N = 200010;

int n,k;
int stk[N];
int top;
map<int,int> mp;

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n;i++){
        int x;scanf("%d",&x);
        if(mp[x])continue;
        mp[x] = 1;
        stk[++top] = x;
        if(top > k){
            mp[stk[top - k]] = 0;
        }
    }
    printf("%d\n",min(k,top));
    for(int i = top;i >= max(top - k + 1,1);i--){
        printf("%d ",stk[i]);
    }
    printf("\n");
}