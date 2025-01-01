//dfs

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;


int n;
int p[N];
bool st[N];
int group[N][N];
int ans;

int gcd(int a,int b){
    
    return b ? gcd(b,a % b) : a;
    
}

bool check(int g[],int gc,int u){
    
    for(int i = 0;i < gc;i++){
        
        if(gcd(p[g[i]],p[u]) > 1)return false;
        
    }
    return true;   
}

void dfs(int g,int gc,int tc,int start){
    
    if(g >= ans)return ;
    if(tc == n){
        ans = g;
    }
    
    bool flag = true;
    
    for(int i = start;i < n;i++){
        
        if(!st[i] && check(group[g],gc,i)){
            st[i] = true;
            group[g][gc] = i;
            dfs(g,gc + 1,tc + 1,i + 1);
            st[i] = false;
            flag = false;
            
            if(gc == 0)return;
            
        }
        
    }
    
    if(flag){
        dfs(g + 1,0,tc,0);
    }
}

int main(){
    
    cin >> n;
    ans = n;
    for(int i = 0;i < n;i++){
        cin >> p[i];
    }
    //当前组 组内位置 已经处理了多少个数 从那个数开始处理
    dfs(1,0,0,0);
    cout << ans << endl;
    return 0;
}