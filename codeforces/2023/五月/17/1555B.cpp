#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 20000010;

typedef long long LL;

void solve(){
    int W,H;scanf("%d%d",&W,&H);
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int w,h;scanf("%d%d",&w,&h);
    int ans = 2e8;

    if(y2 - y1 + h <= H){
        ans = min(ans,max(0,h - y1));
        ans = min(ans,max(0,y2 - H + h));
    }

    if(x2 - x1 + w <= W){
        ans = min(ans,max(0,w - x1));
        ans = min(ans,max(0,x2 - W + w));
    }
    if(ans == 2e8)printf("-1\n");
    else printf("%lf\n",1.0 * ans);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();

    return 0;
}