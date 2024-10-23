//线段树

/*
    线段树，先要build，构建线段树基本结构。
    u的左节点：u << 1 右节点：u << 1 | 1
*/




#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200010;

int m,p;
int n;
LL last;

struct Node{
    int l,r;
    int v;
}tr[N * 4];


void build(int u,int l,int r){
    tr[u] = {l,r};
    
    if(l >= r)return ;
    int mid = l + r >> 1;
    build(u << 1,l,mid);
    build(u << 1 | 1,mid + 1,r);
}

void pushup(int u){
    tr[u].v = max(tr[u << 1].v,tr[u << 1 | 1].v);
}

int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r){
        return tr[u].v;
    }
    int v = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid)v = query(u << 1,l,r);
    if(r > mid)v = max(v,query(u << 1 | 1,l, r));
    return v;
}

void modify(int u,int x,int v){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].v = v;
    }else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid)modify(u << 1,x,v);
        else modify(u << 1 | 1,x,v);
        pushup(u);
        
    }
}

int main(){
    cin >> m >> p;
    build(1,1,m);
    for(int i = 0;i < m;i++){
        string s;cin >> s;
        if(s == "Q"){
            int x;cin >> x;
            last = query(1,n - x + 1,n);
            cout << last << endl;
        }else {
            int x;cin >> x;
            modify(1,++n,(x + last) % p);
        }
    }
    return 0;
}

