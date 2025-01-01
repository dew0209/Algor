//dfs

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 30;

int n,m;

string word[N];
int g[N][N];
int cnt[N];
int ans = 0;

void dfs(string str,int last){
    cnt[last]++;
    ans = max((int)str.size(),ans);
    for(int i = 0;i < n;i++){
        if(cnt[i] < 2 && g[last][i]){
            dfs(str + word[i].substr(g[last][i]),i);
        }
    }
    cnt[last]--;
}

int main(){
    
    cin >> n;
    char start;
    
    for(int i = 0;i < n;i++)cin >> word[i];
    
    cin >> start;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 1;k < min(word[i].size(),word[j].size());k++){
                if(word[i].substr(word[i].size() - k,k) == word[j].substr(0,k)){
                    g[i][j] = k;
                    break;
                }
            }
        }
    }
    
    
    for(int i = 0;i < n;i++){
        if(word[i][0] == start){
            dfs(word[i],i);
        }
    }
    cout << ans << endl;
    return 0;
}