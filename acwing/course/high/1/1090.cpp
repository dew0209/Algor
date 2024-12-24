//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50010;

int n,m;
int g[N];
int f[N];
int q[N];

bool check(int k){
    
    f[0] = 0;
    
    int hh = 0,tt = 0;
    for(int i = 1;i <= n;i++){
        if(hh <= tt && q[hh] < i - k - 1)hh++;
        f[i] = f[q[hh]] + g[i];
        while(hh <= tt && f[q[tt]] >= f[i])tt--;
        q[++tt] = i;
    }
    int res = 0x3f3f3f3f;
    for(int i = n - k;i <= n;i++)res = min(res,f[i]);
    return res <= m;
}


int main(){
    
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++)cin >> g[i];
    
    int l = 0,r = n;
    
    while(l < r){
        
        int mid = l + r >> 1;
        
        if(check(mid)){
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    cout << r << endl;
    return 0;
    
}