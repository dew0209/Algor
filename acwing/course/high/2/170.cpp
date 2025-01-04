//dfs

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int path[N];


bool dfs(int u,int k){
    if(u > k)return false;
    if(u == k){
        return path[u - 1] == n;
    }
    bool st[N] = {0};
    for(int i = u - 1;i >= 0;i--){
        for(int j = i;j >= 0;j--){
            int v = path[i] + path[j];
            if(st[v] || v > n || v <= path[u - 1])continue;
            path[u] = v;
            st[v] = true;
            if(dfs(u + 1,k))return true;
        }
    }
    return false;
}

int main(){
    
    while(cin >> n,n){
        int k = 1;
        path[0] = 1;
        while(!dfs(1,k))k++;
        for(int i = 0;i < k;i++){
            cout << path[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}