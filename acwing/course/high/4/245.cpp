//线段树

/*

    

*/


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 500010;

struct Node{
    int l,r;
    int sum,lmax,rmax,tmax;
}tr[N * 4];

int n,m;
int w[N];

void pushup(Node &u,Node &l,Node &r){
    u.sum = l.sum + r.sum;
    u.lmax = max(l.lmax,l.sum + r.lmax);
    u.rmax = max(r.rmax,r.sum + l.rmax);
    u.tmax = max(max(l.tmax,r.tmax),l.rmax + r.lmax);
}

void pushup(int u){
    pushup(tr[u],tr[u << 1],tr[u << 1 | 1]);
}

void build(int u,int l,int r){
    if(l == r){
        tr[u] = {l,r,w[l],w[l],w[l],w[l]};
    }else {
        tr[u] = {l,r};
        int mid = l + r >> 1;
        build(u << 1,l,mid);
        build(u << 1 | 1,mid + 1,r);
        pushup(u);
    }
}

Node query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r){
        return tr[u];
    }else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid)return query(u << 1,l,r);
        else if(l > mid)return query(u << 1 | 1,l,r);
        else {
            auto left = query(u << 1,l,r);
            auto right = query(u << 1| 1,l,r);
            Node res;
            pushup(res,left,right);
            return res;
        }
    }
}

void modify(int u,int x,int y){
    if(tr[u].l == x && tr[u].r == x){
        tr[u] = {x,x,y,y,y,y};
    }else {
        
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid){
            modify(u << 1,x,y);
        }else {
            modify(u << 1 | 1,x,y);
        }
        pushup(u);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> w[i];
    }
    build(1,1,n);
    for(int i = 1;i <= m;i++){
        int k,x,y;
        cin >> k >> x >> y;
        if(k == 1){
            if(x > y)swap(x,y);
            auto res = query(1,x,y);
            cout << res.tmax << endl;
        }else {
            modify(1,x,y);
        }
    }
    return 0;
}