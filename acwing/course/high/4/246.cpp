//线段树

/*

gcd(a,b,c,d) = gcd(a,b - a,c - b,d - c);

*/

#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 500010;


struct Node{
    int l,r;
    LL sum;
    LL mv;
}tr[N * 4];

int n,m;
LL a[N];

LL gcd(LL a,LL b){
    return b ? gcd(b,a%b) : a;
}


void pushup(Node& u,Node& l,Node& r){
    u.sum = l.sum + r.sum;
    u.mv = gcd(l.mv,r.mv);
}

void pushup(int u){
    pushup(tr[u],tr[u << 1],tr[u << 1 | 1]);
}

void build(int u,int l,int r){
    if(l == r){
        tr[u] = {l,r,a[l] - a[l - 1],a[l] - a[l - 1]};
    }else {
        tr[u] = {l,r};
        int mid = l + r >> 1;
        build(u << 1,l,mid);
        build(u << 1 | 1,mid + 1,r);
        pushup(u);
    }
}

void modfiy(int u,int x,LL v){
    if(tr[u].l == x && tr[u].r == x){
        LL b = tr[u].sum + v;
        tr[u] = {x,x,b,b};
    }else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid)modfiy(u << 1,x,v);
        else modfiy(u << 1 | 1,x,v);
        pushup(u);
    }
}

Node query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r)return tr[u];
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid)return query(u << 1,l,r);
        else if(l > mid)return query(u << 1 | 1,l,r);
        else {
            Node res;
            auto left = query(u << 1,l,r);
            auto right = query(u << 1 | 1,l,r);
            pushup(res,left,right);
            return res;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    build(1,1,n);
    for(int i = 1;i <= m;i++){
        string op;cin >> op;
        if(op == "Q"){
            int l,r;cin >> l >> r;
            Node right({0,0,0,0});
            Node left = query(1,1,l);
            if(l + 1 <= r){
                right = query(1,l + 1,r);
            }
            cout << abs(gcd(left.sum,right.mv)) << endl; 
        }else {
            LL l,r,v;cin >> l >> r >> v;
            modfiy(1,l,v);
            if(r + 1 <= n){
                modfiy(1,r + 1,-v);
            }
        }
    }
    
}
