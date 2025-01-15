//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 510,M = 10010;

int n,m1,m2;
int h[N],e[M],ne[M],w[M],idx;
int dist[N];
int cnt[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

bool spfa(){
    
    memset(dist,0x3f,sizeof dist);
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    queue<int> q;
    for(int i = 1;i <= n;i++){
        q.push(i);
        st[i] = true;
    }
    
    while(q.size()){
        
        auto t = q.front();
        q.pop();
        
        for(int i = h[t];~i;i = ne[i]){
            int j = e[i];
            st[j] = false;
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n)return true;
                if(!st[j]){
                    q.push(j);
                }
            }
            
        }
        
    }
    
    return false;
    
}

void solve(){
    
    memset(h,-1,sizeof h);
    idx = 0;
    
    cin >> n >> m1 >> m2;
    
    for(int i = 0;i < m1;i++){
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    
    for(int i = 0;i < m2;i++){
        
        int a,b,c;cin >> a >> b >> c;
        add(a,b,-c);
        
    }
    
    if(spfa())cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}