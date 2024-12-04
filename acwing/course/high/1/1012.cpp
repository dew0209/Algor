//dp

#include <iostream>
#include <cstring>
#include <algorithm>

#define fi first
#define se second

using namespace std;

typedef pair<int,int> PII;

const int N = 5010;



int n;
PII g[N];
int f[N];


int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> g[i].fi >> g[i].se;
    }
    sort(g,g + n);
    int res = 0;
    for(int i = 0;i < n;i++){
        f[i] = 1;
        for(int j = 0;j < i;j++){
            if(g[i].se > g[j].se){
                f[i] = max(f[i],f[j] + 1);
            }
        }
        res = max(res,f[i]);
    }
    cout << res << endl;
    return 0;
}
