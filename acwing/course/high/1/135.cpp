//dp


#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 300010;

int n,m;
int g[N];
LL s[N];
int q[N];

int main(){
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++)cin >> g[i];
    for(int i = 1;i <= n;i++)s[i] = g[i] + s[i - 1];
    
    int hh = 0,tt = 0;
    LL res = -1e18;
    for(int i = 1;i <= n;i++){
        if(q[hh] < i - m)hh++;
        res = max(s[i] - s[q[hh]],res);
        while(hh <= tt && s[q[tt]] > s[i])tt--;
        q[++tt] = i;
    }
    cout << res << endl;
    return 0;
}