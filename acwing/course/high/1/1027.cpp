//dp


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30;

int n;
int g[N][N];
int f[N][N][N];

int main(){
    
    cin >> n;
    
    int x,y,v;
    while(scanf("%d%d%d",&x,&y,&v),x){
        g[x][y] = v;
    }
    for(int i = 1;i <= 2 * n;i++){
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
    cout << f[n * 2][n][n] << endl;
    return 0;
}