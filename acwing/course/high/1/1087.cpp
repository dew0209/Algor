//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

typedef long long LL;

int n,m;
LL s[N];
int q[N];
LL f[N];

LL g(int i){
    
    if(!i)return 0;
    
    return f[i - 1] - s[i];
    
}

int main(){
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++)cin >> s[i],s[i] += s[i - 1];
    int hh = 0,tt = 0;
    for(int i = 1;i <= n;i++){
        if(q[hh] < i - m)hh++;
        f[i] = max(f[i - 1],g(q[hh]) + s[i]);
        while(hh <= tt && g(q[tt]) <= g(i))tt--;
        q[++tt] = i;
    }
    cout << f[n] << endl;
    
    return 0;
}