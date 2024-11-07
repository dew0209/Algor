//线段树-扫描线


#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

struct Segment{
    double x,y1,y2;
    int d;
    bool operator< (const Segment& t){
        return x < t.x;
    } 
}seg[N * 2];

struct Node{
    int l,r;
    int cnt;
    double len;
}tr[N * 8];


int n;
vector<double> ys;


void build(int u,int l,int r){
    tr[u] = {l,r,0,0};
    if(l != r){
        int mid = l + r >> 1;
        build(u << 1,l,mid);
        build(u << 1 | 1,mid + 1,r);
    }
}

int find(double y){
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}

void pushup(int u){
    if(tr[u].cnt){
        tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    }else if(tr[u].l != tr[u].r){
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    }else tr[u].len = 0;
}

void modify(int u,int l,int r,int v){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].cnt += v;
        pushup(u);
    }else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid)modify(u << 1,l,r,v);
        if(r > mid)modify(u << 1 | 1,l,r,v);
        pushup(u);
    }
}


int main(){
    
    int T = 1;
    while(scanf("%d",&n),n){
        ys.clear();
        for(int i = 0,j = 0;i < n;i++){
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            seg[j++] = {x1,y1,y2,1};
            seg[j++] = {x2,y1,y2,-1};
            ys.push_back(y1);ys.push_back(y2);
        }
        
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        
        build(1,0,ys.size() - 2);
        
        sort(seg,seg + n * 2);
        
        double res = 0;
        
        for(int i = 0;i < n * 2;i++){
            if(i > 0)res += tr[1].len * (seg[i].x - seg[i - 1].x);
            modify(1,find(seg[i].y1),find(seg[i].y2) - 1,seg[i].d);
        }
        printf("Test case #%d\n", T ++ );
        printf("Total explored area: %.2lf\n\n", res);
    }
    
}

