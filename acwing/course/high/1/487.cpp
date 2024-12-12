//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

const int N = 32010;

int n,m;
vector<PII> attachment[N];
PII master[N];
int f[N];

int main(){
    cin >> m >> n;
    int v,p,q;
    for(int i = 1;i <= n;i++){
        cin >> v >> p >> q;
        p *= v;
        if(!q){
            master[i] = {v,p};
        }else {
            attachment[q].push_back({v,p});
        }
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= 0;j--){
            for(int u = 0;u < 1 << attachment[i].size();u++){
                int v = master[i].first;
                int w = master[i].second;
                for(int k = 0;k < attachment[i].size();k++){
                    if((u >> k) & 1){
                        v += attachment[i][k].first;
                        w += attachment[i][k].second;
                    }
                }
                if(j >= v)f[j] = max(f[j],f[j - v] + w);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}