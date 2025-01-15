//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 1010,M = 100010;

int n;
int h[N],e[M],ne[M],w[M],idx;
double dist[N];
int cnt[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c;
    h[a] = idx++;
}

bool check(double mid){
    
    memset(st,0,sizeof st);
    memset(dist,0,sizeof dist);
    memset(cnt,0,sizeof cnt);
    stack<int> q;
    for(int i = 0;i < 676;i++){
        q.push(i);
        st[i] = true;
    }
    
    while(q.size()){
        int t = q.top();
        q.pop();
        st[t] = false;
        for(int i = h[t];~i;i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i] - mid){
                dist[j] = dist[t] + w[i] - mid;
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= 676)return true;
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
    
    char str[1010];
    
    while(scanf("%d",&n),n){
        memset(h,-1,sizeof h);
        idx = 0;
        
        for(int i = 0;i < n;i++){
            scanf("%s",str);
            int len = strlen(str);
            if(len >= 2){
                int left = (str[0] - 'a') * 26 + str[1] - 'a';
                int right = (str[len - 2] - 'a') * 26 + str[len - 1] - 'a';
                add(left,right,len);
            }
        }
        if(!check(0))puts("No solution");
        else {
            
            double l = 0,r = 1000;
            
            while(r - l > 1e-4){
                
                double mid = (l + r) / 2;
                if(check(mid))l = mid;
                else r = mid;
            }
            printf("%.2lf\n",l);
        }
    }
    return 0;   
}