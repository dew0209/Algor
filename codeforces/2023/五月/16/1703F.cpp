#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200010;

typedef long long LL;

int n,m;
int q[N];

void solve(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
    }
    LL res = 0;
    vector<int> c;
    for(int i = 1;i <= n;i++){
        if(q[i] < i){
            res = res + (LL)(lower_bound(c.begin(),c.end(),q[i]) - c.begin());
            c.push_back(i);
        }
    }
    
    //printf("\n");
    printf("%lld\n",res);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}