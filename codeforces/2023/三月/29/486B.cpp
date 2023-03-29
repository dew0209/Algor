#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,LL> PIL;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;

const int N = 110,M = 200010;

int n,m;
int g[N][N];
int res[N][N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",&g[i][j]);
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            res[i][j] = 1;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(g[i][j] == 0){
                for(int u = 0;u < n;u++){
                    res[u][j] = 0;
                }
                for(int u = 0;u < m;u++){
                    res[i][u] = 0;
                }
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(g[i][j]){
                int ok = 0;
                for(int u = 0;u < n;u++){
                    if(res[i][u]){
                        ok = 1;
                    }
                }
                for(int u = 0;u < m;u++){
                    if(res[u][j]){
                        ok = 1;
                    }
                }
                if(!ok){
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}