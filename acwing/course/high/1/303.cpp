//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010,M = 110;

int n,m,p;
LL f[M][N];
LL d[N],t[N],a[N],s[N];
int q[N];

LL get_y(int k,int i){
    
    return f[i - 1][k] + s[k];
    
}

int main(){
    cin >> n >> m >> p;
    
    for(int i = 2;i <= n;i++){
        cin >> d[i];
        d[i] += d[i - 1];
    }
    
    for(int i = 1;i <= m;i++){
        
        int h;
        cin >> h >> t[i];
        
        a[i] = t[i] - d[h];
        
    }
    
    sort(a + 1,a + m + 1);
    
    for(int i = 1;i <= m;i++)s[i] = a[i] + s[i - 1];
    
    memset(f,0x3f,sizeof f);
    
    for(int i = 0;i <= p;i++)f[i][0] = 0;
    
    for(int i = 1;i <= p;i++){
        
        int hh = 0,tt = 0;
        q[0] = 0;
        
        for(int j = 1;j <= m;j++){
            
            while(hh < tt && (get_y(q[hh + 1], i) - get_y(q[hh],i)) <= 
                a[j] * (q[hh + 1] - q[hh]))hh++;
            f[i][j] = (j - q[hh]) * a[j] - s[j] + get_y(q[hh],i);
            
            while(hh < tt && (get_y(q[tt],i) - get_y(q[tt - 1],i)) * (j - q[tt]) >= (get_y(j,i) - get_y(q[tt],i)) * (q[tt] - q[tt - 1]))tt--;
            
            q[++tt]  = j;
            
        }
        
    }
    cout << f[p][m] << endl;
    
    return 0;
}