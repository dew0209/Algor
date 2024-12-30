//dp

#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 300010;

int n,s;
int c[N],t[N];
LL sc[N],st[N];
LL f[N];
int q[N];

int main(){
    
    cin >> n >> s;
    
    for(int i = 1;i <= n;i++){
        cin >> t[i] >> c[i];
        st[i] = t[i] + st[i - 1];
        sc[i] = c[i] + sc[i - 1];
    }
    
    int hh = 0,tt = 0;
    
    for(int i = 1;i <= n;i++){
        
        while(hh < tt && (f[q[hh + 1]] - f[q[hh]]) <= (st[i] + s) * (sc[q[hh + 1]] - sc[q[hh]]))hh++;
        
        int j = q[hh];
        
        f[i] = f[j] - (st[i] + s) * sc[j] + st[i] * sc[i] + s * sc[n];
        
        while(hh < tt && (f[q[tt]] - f[q[tt - 1]]) * (sc[i] - sc[q[tt - 1]]) >= (f[i] - f[q[tt - 1]]) * (sc[q[tt]] - sc[q[tt - 1]]))tt--;
        
        q[++tt] = i;
    }
    
    cout << f[n] << endl;
    return 0;
}