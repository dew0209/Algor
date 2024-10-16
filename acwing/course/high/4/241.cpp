//树状数组

/*
    凸形状的：当前节点为y，统计左边小于y的，右边小于y的。
    凹形状的：当前节点为y，统计左边大于y的，右边大于y的。
    树状数组统计从起始节点到当前节点每个数出现了多少次，小于的就是sum(y - 1) 大于的就是sum(n) - sum(y)
*/


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200010;

int n;
int tr[N];
LL down[N],up[N];
int a[N];

int lowbit(int u){
    return u & -u;
}

void add(int x,LL y){
    for(int i = x;i <= n;i += lowbit(i)){
        tr[i] += y;   
    }
}

LL sum(int u){
    
    LL res = 0;
    for(int i = u;i;i -= lowbit(i)){
        res += tr[i];
    }
    return res;
}

int main(){
    
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    
    for(int i = 1;i <= n;i++){
        int y = a[i];
        down[i] = sum(y - 1);
        up[i] = sum(n) - sum(y);
        add(y,1);
    }
    
    memset(tr,0,sizeof tr);
    
    LL res = 0;
    LL ans = 0;
    
    for(int i = n;i > 0;i--){
        int y = a[i];
        res += down[i] * sum(y - 1);
        ans += up[i] * (sum(n) - sum(y));
        add(y,1);
    }
    printf("%lld %lld\n",ans,res);
    return 0;
}