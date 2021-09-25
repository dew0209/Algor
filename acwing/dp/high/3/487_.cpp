#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef pair<int,int> PII;

const int N = 60,M = 100010;

int n,m;
PII master[N];
vector<PII> servent[N];
int f[M];

int main(){
    cin >> m >> n;
    for(int i = 1;i <= n;i++){
        int v,p,q;
        cin >> v >> p >> q;
        p *= v;
        if(!q)master[i] = {v,p};
        else servent[q].push_back({v,p});
    }
    for(int i = 1;i <= n;i++){
        for(int u = m;u >= 0;u--){
            for(int j = 0;j < 1 << servent[i].size();j++){
                int v = master[i].fi,w = master[i].se;
                for(int k = 0;k < servent[i].size();k++){
                    if(j >> k & 1){
                        v += servent[i][k].fi;
                        w += servent[i][k].se;
                    }
                }
                if(u >= v)f[u] = max(f[u],f[u - v] + w);
            }
        }
    }
    cout << f[m] << endl;

    return 0;
}
