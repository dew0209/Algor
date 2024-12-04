//dp


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 60;

int n,m;
int g[N][N];
int f[N * 2][N][N];

int main(){
    
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> g[i][j];
        }
    }
    
    for(int i = 1;i <= n + m;i++){
        for(int ax = 1;ax < i;ax++){
            for(int bx = 1;bx < i;bx++){
                
                int ay = i - ax;
                int by = i - bx;
                
                int t = g[ax][ay];
                if(ax != bx){
                    t += g[bx][by];
                }
                int& res = f[i][ax][bx];
                
                res = max(res,f[i - 1][ax - 1][bx] + t);
                res = max(res,f[i - 1][ax][bx - 1] + t);
                res = max(res,f[i - 1][ax - 1][bx - 1] + t);
                res = max(res,f[i - 1][ax][bx] + t);
            }
        }
    }
    cout << f[n + m][n][n] << endl;
    return 0;
}