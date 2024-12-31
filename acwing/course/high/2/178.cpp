//A*

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1010,M = 200010;

#define fi first
#define se second

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int n,m,S,T,K;
int h[N],rh[N],e[M],w[M],ne[M],idx;
int dist[N],cnt[N];
bool st[N];

void add(int h[],int a,int b,int c){
    w[idx] = c;
    ne[idx] = h[a];
    e[idx] = b;
    h[a] = idx++;
}

void dijkstra(){
    
    priority_queue<PII,vector<PII>,greater<PII>> headp;
    
    headp.push({0,T});
    memset(dist,0x3f,sizeof dist);
    
    dist[T] = 0;
    
    while(headp.size()){
        auto t = headp.top();
        headp.pop();
        int ver = t.se;
        if(st[ver])continue;
        st[ver] = true;
        for(int i = rh[ver];~i;i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                headp.push({dist[j],j});
            }
        }
    }
}

int astar(){
    
    priority_queue<PIII,vector<PIII>,greater<PIII>> heap;
    heap.push({dist[S] + 0,{0,S}});
    
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.se.se;
        int distance = t.se.fi;
        cnt[ver]++;
        if(cnt[T] == K)return distance;
        for(int i = h[ver];~i;i = ne[i]){
            int j = e[i];
            if(cnt[j] < K){
                heap.push({distance + w[i] + dist[j],{distance + w[i],j}});
            }
        }
        
    }
    return -1;
}

int main(){
    
    cin >> n >> m;
    memset(h,-1,sizeof h);
    memset(rh,-1,sizeof rh);
    
    for(int i = 0;i < m;i++){
        int a,b,c;cin >> a >> b >> c;
        add(h,a,b,c);
        add(rh,b,a,c);
    }
    
    cin >> S >> T >> K;
    if(S == T)K++;
    dijkstra();
    
    cout << astar() << endl;
    
    return 0;
    
}