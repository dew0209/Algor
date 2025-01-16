//图论

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 50010,M = N * 3;

int n,m;
int h[N],e[M],ne[M],w[M],idx;
int dist[N];
bool st[N];
int cnt[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

void spfa(){
    
    
    queue<int> q;
    
    memset(dist,-0x3f,sizeof dist);
    dist[0] = 0;
    q.push(0);
    
    st[0] = true;
    
    while(q.size()){
        
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for(int i = h[t];~i;i = ne[i]){
            
            int j = e[i];
            if(dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
                
            }
            
        }
        
    }
    
}


int main(){
    
    cin >> n;
    
    memset(h,-1,sizeof h);
    
    for(int i = 1;i <= 50001;i++){
        add(i - 1,i,0);
        add(i,i - 1,-1);
    }
    
    for(int i = 0;i < n;i++){
        
        int a,b,c;cin >> a >> b >> c;
        a++;
        b++;
        add(a - 1,b,c);
    }
    spfa();
    cout << dist[50001] << endl;
    return 0;
}