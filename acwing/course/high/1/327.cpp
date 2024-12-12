//dp

#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 15,M = (1 << 12) + 10;
const int MOD = 1e8;

int n,m;
LL f[N][M];
int g[N][N];
vector<int> state;
vector<int> head[M];


bool check(int u){
    
    for(int i = 0;i < N;i++){
        if(((u >> i) & 1) && ((u >> (i + 1)) & 1)){
            return false;
        }
    }
    return true;
    
}

bool check(int h[],int u){
    
    for(int i = 0;i < m;i++){
        if(h[i] == 1 & ((u >> i) & 1)){
            return false;
        }
    }
    return true;
}

int main(){
    
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < m;j++){
            cin >> g[i][j];
            if(g[i][j] == 1){
                g[i][j]= 0;
            }else {
                g[i][j] = 1;
            }
        }
    }
    
    for(int i = 0;i < m;i++){
        g[0][i] = 1;
    }
    
    for(int i = 0;i < 1 << m;i++){
        if(check(i)){
            state.push_back(i);
        }
    }
    int len = state.size();
    
    for(int i = 0;i <= n + 1;i++){
        for(int j = 0;j < len;j++){
            if(check(g[i],state[j])){
                head[i].push_back(j);
            }
        }
    }
    
    for(int i = 0;i < 1 << m;i++){
        f[0][i] = 1;
    }
    
    for(int i = 1;i <= n + 1;i++){
        for(auto j : head[i]){
            for(auto k : head[i - 1]){
                int a = state[j];
                int b = state[k];
                if((a & b ) == 0){
                    f[i][j] = (f[i][j] + f[i - 1][k]) % MOD;
                }
            }
        }
    }
    cout << f[n + 1][0] << endl;
    
    return 0;
}