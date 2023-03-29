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
 
const int N = 1010,M = 200010;
 
int n;
int p[M];
int st[M];
int res[M];
 
void solve(){
    memset(p,0,sizeof p);
    memset(st,0,sizeof st);
    memset(res,0,sizeof res);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&p[i]);
    }
    for(int i = 1;i <= n;i++){
        if(!st[i]){
            vector<int> a;
            int j = i;
            int cnt = 0;
            do{
                cnt++;
                st[j] = 1;
                a.pb(j);
                j = p[j];
            } while (j != i && !st[j]);
            for(int u : a){
                res[u] = cnt;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        printf("%d ",res[i]);
    }
}
 
int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}