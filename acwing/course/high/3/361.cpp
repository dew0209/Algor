//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1010,M = 5010;

int n,m;
int h[N],e[M],ne[M],w[M],idx;
double dist[N];
int cnt[N];
bool st[N];
int f[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

bool check(double mid){
    
    memset(dist,0,sizeof dist);
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);
    
    queue<int> q;
    
    for(int i = 1;i <= n;i++){
        q.push(i);
        st[i] = true;
    }
    
    while(q.size()){
        
        auto t = q.front();
        q.pop();
        
        st[t] = false;
        
        for(int i = h[t];~i;i = ne[i]){
            
            int j = e[i];
            if(dist[j] < dist[t] + f[t] - w[i] * mid){
                
                dist[j] = dist[t] + f[t] - w[i] * mid;
                
                cnt[j] = cnt[t] + 1;
                
                if(cnt[j] >= n)return true;
                
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
                
            }
            
        }
        
    }
    
    return false;
    
}

int main(){
    memset(h,-1,sizeof h);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> f[i];
    for(int i = 0;i < m;i++){
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);
    }
    double l = 0,r = 1000;
    double eps = 1e-4;
    while(eps < r - l){
        double mid = (l + r) / 2;
        if(check(mid))l = mid;
        else r = mid;
    }
    printf("%.2lf\n",l);
    return 0;
}