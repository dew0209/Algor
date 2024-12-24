//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n,m;
int w[N];
int q[N];
int f[N];

int main(){
    
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++){
        cin >> w[i];
    }
    
    int hh = 0,tt = 0;
    
    for(int i = 1;i <= n;i++){
        
        if(hh <= tt && q[hh] < i - m)hh++;
        
        f[i] = f[q[hh]] + w[i];
        
        while(hh <= tt && f[q[tt]] >= f[i])tt--;
        q[++tt] = i;
    }
    
    int res = 0x3f3f3f3f;
    
    for(int i = n - m + 1;i <= n;i++)res = min(res,f[i]);
    cout << res << endl;
    return 0;
}