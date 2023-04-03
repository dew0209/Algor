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
 
const int N = 200010,M = 200010;

int n,m;
int f[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        f[x] = f[y] = 1;
    }
    for(int i = 1;i <= n;i++){
        if(!f[i]){
            printf("%d\n",n - 1);
            for(int j = 1;j <= n;j++){
                if(i != j){
                    printf("%d %d\n",i,j);
                }
            }
            break;
        }
    }
    return 0;
}