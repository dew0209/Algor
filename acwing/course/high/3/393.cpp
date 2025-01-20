//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>


using namespace std;

const int N = 30,M = 100;

int n;
int h[N],e[M],ne[M],w[M],idx;
int r[N];
int num[N];
int cnt[N];
bool st[N];
int dist[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

void build(int c){
    
    idx = 0;
    memset(h,-1,sizeof h);
    memset(dist,-0x3f,sizeof dist);
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    
    add(0, 24, c), add(24, 0, -c);
    
    for(int i = 1;i <= 24;i++){
        add(i - 1,i,0);
        add(i,i - 1,-num[i]);
    }
    
    for(int i = 8;i <= 24;i++){
        add(i - 8,i,r[i]);
    }
    
    for(int i = 1;i <= 7;i++){
        add(i + 16,i,r[i] - c);
    }
}

bool spfa(int c){
    
    build(c);
    
    queue<int> q;
    
    q.push(0);
    dist[0] = 0;
    st[0] = true;
    
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t];~i;i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= 25)return false;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return true;
}

int main(){
    
    int t;cin >> t;
    while(t--){
        
        for(int i = 1;i <= 24;i++){
            cin >> r[i];
        }
        memset(num, 0, sizeof num);
        cin >> n;
        for(int i = 0;i < n;i++){
            int a;cin >> a;
            num[a + 1]++;
        }
        bool success = false;
        for(int i = 0;i <= 1000;i++){
            if(spfa(i)){
                cout << i << endl;
                success = true;
                break;
            }
        }
        if(!success){
            cout << "No Solution" << endl;
        }
    }
    
    return 0;
}