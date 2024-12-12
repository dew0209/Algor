//dp

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long LL;

using namespace std;

const int N = 20,M = 1100;

int n,m;
LL f[N][M][N * N];
vector<int> state;
vector<int> head[M];
int cnt[M];

int lowbit(int u){
    
    int res = 0;
    while(u){
        u -= u & -u;
        res++;
    }
    return res;
}

bool check(int u){
    
    for(int i = 0;i < N;i++){
        if(((u >> i) & 1) && ((u >> (i + 1)) & 1)){
            return false;
        }
    }
    return true;
}

int main(){
    
    cin >> n >> m;
    
    for(int i = 0;i < 1 << n;i++){
        if(check(i)){
            state.push_back(i);
            cnt[i] = lowbit(i);
        }
    }
    
    int len = state.size();
    
    for(int i = 0;i < len;i++){
        for(int j = 0;j < len;j++){
            int a = state[i];
            int b = state[j];
            if((a & b) == 0 && check(a | b)){
                head[i].push_back(j);
            }
        }
    }
    
    f[0][0][0] = 1;
    
    for(int i = 1;i <= n + 1;i++){
        for(int j = 0;j < len;j++){
            for(int k = cnt[state[j]];k <= m;k++){
                for(auto u : head[j]){
                    f[i][state[j]][k] += f[i - 1][state[u]][k - cnt[state[j]]];
                }
            }
            
        }
    }
    cout << f[n + 1][0][m] << endl;
    return 0;
}