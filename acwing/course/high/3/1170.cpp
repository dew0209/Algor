//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const int N = 1010,M = N + 20010;
const int INF = 0x3f3f3f3f;

int n,m1,m2;
int h[N],e[M],ne[M],w[M],idx;
int dist[N];
bool st[N];
int cnt[N];
int q[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

bool spfa(int S){
    queue<int> q;
    memset(dist,0x3f,sizeof dist);
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    dist[S] = 0;
    q.push(S);
    st[S] = true;
    while(q.size()){
        
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t];~i;i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
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
    
    cin >> n >> m1 >> m2;
    
    for(int i = 1;i < n;i++){
        add(i + 1,i,0);
    }
    
    for(int i = 0;i < m1;i++){
        
        int a,b,l;cin >> a >> b >> l;
        if(a > b)swap(a,b);
        add(a,b,l);
    }
    
    for(int i = 0;i < m2;i++){
        int a,b,d;cin >> a >> b >> d;
        if(a > b)swap(a,b);
        add(b,a,-d);
    }
    if(spfa(n))cout << -1 << endl;
    else {
        spfa(1);
        int res = dist[n];
        if(res >= INF / 2)cout << -2 << endl;
        else cout << res << endl;
    }
    return 0;
}