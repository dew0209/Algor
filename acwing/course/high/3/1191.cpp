//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110,M = N * 2;

int n;
int h[N],e[M],ne[M],idx;
int d[N];
int q[N];

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void topsort(){
    
    int hh = 0,tt = -1;
    
    for(int i = 1;i <= n;i++){
        
        if(d[i] == 0){
            q[++tt] = i;
        }
    }
    
    while(hh <= tt){
        
        int t = q[hh++];
        
        for(int i = h[t];~i;i = ne[i]){
            
            int j = e[i];
            
            d[j]--;
            
            if(d[j] == 0){
                q[++tt] = j;
            }
        }
    }
}

int main(){
    
    memset(h,-1,sizeof h);
    
    cin >> n;
    
    for(int i = 1;i <= n;i++){
        int son;
        while(cin >> son,son){
            add(i,son);
            d[son]++;
        }
    }
    
    topsort();
    
    for(int i = 0;i < n;i++)printf("%d ",q[i]);
    return 0;
}