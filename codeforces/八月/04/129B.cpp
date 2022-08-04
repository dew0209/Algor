#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7;

int n,m;
int d[110];
int e[110];
int cnt[110][110];

int main(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a,b;cin >> a >> b;
        d[a]++;
        d[b]++;
        cnt[a][b] = 1;
        cnt[b][a] = 1;
    }
    int cc = 1;
    int ans = 0;
    while(cc > 0){
        cc = 0;
        for(int i = 1;i <= n;i++){
            if(d[i] == 1)e[cc++] = i,d[i]--;
        }
        for(int i = 0;i < cc;i++){
            for(int j = 1;j <= n;j++){
                if(cnt[e[i]][j]){
                    d[j]--;
                }
            }
        }
        if(cc)ans++;
    }
    cout << ans << endl;
}