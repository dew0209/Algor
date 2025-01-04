//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2010,M = 200010;

int n,m,S,T;
int h[N],e[M],ne[M];
double w[M];
int idx;
double dist[N];
bool st[N];

void add(int a,int b,double c){
    
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
    
}

void spfa(){
    dist[S] = 1;
    st[S] = true;
    queue<int> q;
    q.push(S);
    while(q.size()){
        auto t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t];~i;i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] * w[i]){
                
                dist[j] = dist[t] * w[i];
                
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
                
            }
        }
    }
}

int main(){
    
    memset(h,-1,sizeof h);
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a,b;
        double c;
        cin >> a >> b >> c;
        add(a,b,(100 - c) / 100);
        add(b,a,(100 - c) / 100);
    }
    cin >> S >> T;
    spfa();
    printf("%.8lf",100 / dist[T]);
    return 0;
}