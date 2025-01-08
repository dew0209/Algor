//图论

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

const int N = 100010,M = 2000010,INF = 0x3f3f3f3f;

int n,m;
int hs[N],hr[N],e[M],ne[M],idx;
int w[N];
int dmin[N],dmax[N];
bool st[N];

void add(int h[],int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void spfa(int h[],int S,bool maxFlag){
    
    queue<int> q;
    
    if(maxFlag){
        memset(dmax,-0x3f,N * 4);
        memset(st,0,sizeof st);
        dmax[S] = w[S];
        q.push(S);
    }else {
        memset(dmin,0x3f,N * 4);
        memset(st,0,sizeof st);
        dmin[S] = w[S];
        q.push(S);
    }
    
    while(q.size()){
        
        auto t = q.front();
        q.pop();
        st[t] = false;
        
        if(maxFlag){
            
            for(int i = h[t];~i;i = ne[i]){
                
                int j = e[i];
                
                if(dmax[j] < max(dmax[t],w[j])){
                    dmax[j] = max(dmax[t],w[j]);
                    if(!st[j]){
                        q.push(j);
                        st[j] = true;
                    }
                }
                
            }
            
        }else {
            
            for(int i = h[t];~i;i = ne[i]){
                
                int j = e[i];
                
                if(dmin[j] > min(dmin[t],w[j])){
                    dmin[j] = min(dmin[t],w[j]);
                    if(!st[j]){
                        q.push(j);
                        st[j] = true;
                    }
                }
                
            }
        }
        
    }
    
}

int main(){
    cin >> n >> m;
    
    memset(hr,-1,sizeof hr);
    memset(hs,-1,sizeof hs);
    
    for(int i = 1;i <= n;i++)cin >> w[i];
    
    for(int i = 0;i < m;i++){
        
        int a,b,c;
        cin >> a >> b >> c;
        add(hr,a,b);
        add(hs,b,a);
        
        if(c == 2){
            add(hr,b,a);
            add(hs,a,b);
        }
        
    }
    
    spfa(hr,1,false);
    spfa(hs,n,true);
    
    int res = 0;
    
    for(int i = 1;i <= n;i++){
        res = max(dmax[i] - dmin[i],res);
    }
    cout << res << endl;
    return 0;
}