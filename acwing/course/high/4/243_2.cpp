//线段树

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

typedef long long LL;

struct Node{
    int l,r;
    LL sum = 0,add = 0;
}tr[N * 4];

int n,m;
int a[N];

void pushup(Node& root,Node& left,Node& right){
    root.sum = left.sum + right.sum;
}

void pushup(int u){
    pushup(tr[u],tr[u << 1],tr[u << 1 | 1]);
}

void pushdown(int u){
    Node& root = tr[u];
    Node& left = tr[u << 1];
    Node& right = tr[u << 1 | 1];
    if(root.add){
        left.add += root.add;
        left.sum += (LL)(left.r - left.l + 1) * root.add; 
        
        right.add += root.add;
        right.sum += (LL)(right.r - right.l + 1) * root.add; 
        
        root.add = 0;
    }
    
}

void build(int u,int l,int r){
    if(l == r){
        tr[u] = {l,r,a[l],a[l]};
    }else {
        tr[u] = {l,r};
        int mid = l + r >> 1;
        build(u << 1,l,mid);
        build(u << 1 | 1,mid + 1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,LL v){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * v;
        tr[u].add += v;
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid)modify(u << 1,l,r,v);
        if(r > mid)modify(u << 1 | 1,l,r,v);
        pushup(u);
    }
}

Node query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r){
        return tr[u];
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid)return query(u << 1,l,r);
        else if(l > mid)return query(u << 1 | 1,l,r);
        else {
            Node res;
            Node left = query(u << 1,l,r);
            Node right = query(u << 1 | 1,l,r);
            pushup(res,left,right);
            return res;
        }
    }
    
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    build(1,1,n);
    for(int i = 0;i < m;i++){
        string op;cin >> op;
        if(op == "Q"){
            int l,r;cin >> l >> r;
            Node res = query(1,l,r);
            cout << res.sum << endl;
        }else {
            int l,r,v;cin >> l >> r >> v;
            modify(1,l,r,v);
        }
        
    }
}
