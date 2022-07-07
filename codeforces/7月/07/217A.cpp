#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int a[N],b[N];
int st[N];

int n;

void dfs(int u){
    st[u] = 1;
    for(int i = 1;i <= n;i++){
        if(a[i] == a[u] || b[i] == b[u]){
            if(!st[i]){
                dfs(i);
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
    }
    int ans = -1;
    for(int i = 1;i <= n;i++){
        if(!st[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
}