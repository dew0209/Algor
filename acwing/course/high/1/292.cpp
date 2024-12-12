//dp


#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1 << 10;

int n,m;
int f[2][N][N];
int h[N];
int cnt[N];
vector<int> state;

int lowbit(int u){
    int res = 0;
    while(u){
        u -= u & -u;
        res++;
    }
    return res;
}

bool check(int u){
    
    for(int i = 0;i < 12;i++){
        int a = u >> i & 1;
        int b = (u >> i + 1) & 1;
        int c = (u >> i + 2) & 1;
        if(a && (b || c)){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    char c;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < m;j++){
           cin >> c;
           h[i] += (c == 'H') << j;
        }
    }
    
    for(int i = 0;i < 1 << m;i++){
        if(check(i)){
            state.push_back(i);
            cnt[i] = lowbit(i);
        }
    }
    
    int len = state.size();
    
    for(int i = 1;i <= n + 2;i++){
        
        for(int j = 0;j < len;j++){
            
            for(int k = 0;k < len;k++){

                for(int u = 0;u < len;u++){
                    int a = state[j];
                    int b = state[k];
                    int c = state[u];
                    if((h[i] & a ) || (h[i - 1] & b))continue;
                    if((a & b) || (a & c) || (b & c))continue;
                    f[i & 1][j][k] = max(f[i & 1][j][k],f[i - 1 & 1][k][u] + cnt[a]);
                }
            }
        }
    }
    cout << f[n + 2 & 1][0][0] << endl;
    return 0;
}