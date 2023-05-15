#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n,d;
int q[N];
int que[N];

int main(){
    scanf("%d%d",&n,&d);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    LL ans = 0;
    int hh = 0,tt = -1;
    for(int i = 0;i < n;i++){
        while(hh <= tt && q[i] - q[que[hh]] > d)hh++;
        if(hh <= tt){
            LL len = que[tt] - que[hh] + 1;
            ans = ans + len * 1LL * (len - 1) / 2;
        }
        que[++tt] = i;
    }
    printf("%lld\n",ans);
}