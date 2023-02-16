#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

using namespace std;

const int N = 200010,MOD = 1e9 + 7;

int n;
int q[110][110];

void solve(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        string c;
        cin >> c;
        for(int j = 1;j <= n;j++){
            q[i][j] = c[j - 1] - '0';
        }
    }1
    int ok = 1;
    for(int i = 1;i < n;i++){
        for(int j = 1;j < n;j++){
            if(q[i][j]){
                //printf("%d %d %d %d\n",i,j,q[i + 1][j],q[i][j + 1]);
                if(!q[i + 1][j] && !q[i][j + 1]){
                    ok = 0;
                    break;
                }
            }
        }
    }
    if(ok)printf("Yes");
    else printf("No");
}


int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}