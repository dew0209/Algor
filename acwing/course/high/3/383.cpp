//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1010,M = 20010;

int n,m;
int S,T;
int h[N],e[M],ne[M],w[M],idx;
int dist[N][2],cnt[N][2];
bool st[N][2];

struct Ver{
    
    int id,type,dist;
    bool operator> (const Ver &w) const{
        return dist > w.dist;
    }
};

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

int dijkstra(){
    
    memset(st,0,sizeof st);
    memset(dist,0x3f,sizeof dist);
    memset(cnt,0,sizeof cnt);
    
    dist[S][0] = 0,cnt[S][0] = 1;
    priority_queue<Ver,vector<Ver>,greater<Ver>> q;
    q.push({S,0,0});
    
    while(q.size()){
        
        Ver t = q.top();
        q.pop();
        
        int ver = t.id,type = t.type,distance = t.dist,count = cnt[ver][type];
        if(st[ver][type])continue;
        st[ver][type] = true;
        for(int i = h[ver];~i;i = ne[i]){
            
            int j = e[i];
            if(dist[j][0] > distance + w[i]){
                
                dist[j][1] = dist[j][0],cnt[j][1] = cnt[j][0];
                q.push({j,1,dist[j][1]});
                
                dist[j][0] = distance + w[i],cnt[j][0] = count;
                q.push({j,0,dist[j][0]});
            }else if(dist[j][0] == distance + w[i])cnt[j][0] += count;
            else if(dist[j][1] > distance + w[i]){
                dist[j][1] = distance + w[i],cnt[j][1] = count;
                q.push({j,1,dist[j][1]});
            }else if(dist[j][1] == distance + w[i])cnt[j][1] += count;
        }
    }
    int res = cnt[T][0];
    if(dist[T][0] + 1 == dist[T][1])res += cnt[T][1];
    return res;
}

int main(){
    
    int t;cin >> t;
    while(t--){
        
        memset(h,-1,sizeof h);
        idx = 0;
        cin >> n >> m;
        for(int i = 0;i < m;i++){
            int a,b,c;cin >> a >> b >> c;
            add(a,b,c);
        }
        cin >> S >> T;
        cout << dijkstra() << endl;
    }
    return 0;
}