//dfs

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100;

int n;
int sum;
int w[N];
int length;
bool st[N];

bool dfs(int u,int cur,int start){
    
    if(start < n && w[start] > length)return false;
    
    if(u * length == sum){
        return true;    
    }
    
    if(cur == length)return dfs(u + 1,0,0);
    
    for(int i = start;i < n;i++){
        
        if(st[i] || cur + w[i] > length)continue;
        
        st[i] = true;
        
        if(dfs(u,cur + w[i],i + 1))return true;
        
        st[i] = false;
        
        if(!cur || cur + w[i] == length)return false;
        
        int j = i;
        while(j < n && w[i] == w[j])j++;
        
        i = j - 1;
    }
    return false;
}

int main(){
    
    while(cin >> n,n){
        
        memset(st,0,sizeof st);
        
        sum = 0;
        for(int i = 0;i < n;i++){
            cin >> w[i];
            sum += w[i];
        }
        
        sort(w,w + n);
        reverse(w, w + n);
        
        length = 1;
        while(true){
            if(sum % length == 0 && dfs(0,0,0)){
                cout << length << endl;
                break;
            }
            length++;
        }
        
    }
    
    return 0;
    
}