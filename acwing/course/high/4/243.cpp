//树状数组


/*

    Sn = a1 + a2 + a3 + ... + an
    Sn = d1
         d1 + d2
         d1 + d2 + d3
         d1 + d2 + d3 + d4
         ...
         d1 + d2 + d2 + d4 + dn
    补全：
    (d1 d2 d3 d4 ... dn
    d1 (d2 d3 d4 ... dn)
    d1 d2 (d3 d4 ... dn)
    ...
    d1 d2 d3 d4 ... dn
    即：
        Sn = sum(n) * (n + 1) - sum(dn * n);
        需要构建两个树状数组，一个是 dn  一个是 dn * n

*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n,m;
LL tr1[N],tr2[N];
int a[N];


int lowbit(int u){
    return u & -u;
}

LL sum(LL tr[],int u){
    LL res = 0;
    for(int i = u;i;i -= lowbit(i)){
        res += tr[i];
    }
    return res;
}

void add(LL tr[],int u,LL c){
    for(int i = u;i <= n;i += lowbit(i)){
        tr[i] += c;
    }
}

int main(){
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    
    for(int i = 1;i <= n;i++){
        int d = a[i] - a[i - 1];
        add(tr1,i,d);
        add(tr2,i,(LL)i * d);
    }
    
    for(int i = 1;i <= m;i++){
        string s;cin >> s;
        if(s == "C"){
            int l,r,c;
            cin >> l >> r >> c;
            add(tr1,l,c);
            add(tr1,r + 1,-c);
            add(tr2,l,(LL)l * c);
            add(tr2,r + 1,-(LL)(r + 1) * c);
        }else {
            int l, r;cin >> l >> r;
            l--;
            LL res = sum(tr1,r) * (r + 1) - sum(tr2,r) - (sum(tr1,l) * (l + 1) - sum(tr2,l));
            printf("%lld\n",res);
        }
    }
    return 0;
}