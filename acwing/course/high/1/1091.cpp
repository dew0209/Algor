//dp

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n,m,k;
int g[N][N];
int q[N];
int row_min[N][N];
int row_max[N][N];

void get_min(int a[],int b[],int tol){
    int hh = 0,tt = 0;
    for(int i = 1;i <= tol;i++){
        if(hh <= tt && q[hh] <= i - k)hh++;
        while(hh <= tt && a[q[tt]] >= a[i])tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}


void get_max(int a[],int b[],int tol){
    int hh = 0,tt = 0;
    for(int i = 1;i <= tol;i++){
        if(hh <= tt && q[hh] <= i - k)hh++;
        while(hh <= tt && a[q[tt]] <= a[i])tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

int main(){
    
    cin >> n >> m >> k;
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> g[i][j];
        }
    }
    
    for(int i = 1;i <= n;i++){
        get_min(g[i],row_min[i],m);
        get_max(g[i],row_max[i],m);
    }
    
    int a[N],b[N],c[N];
    
    int res = 0x3f3f3f3f;
    
    for(int i = k;i <= m;i++){
        
        for(int j = 1;j <= n;j++)a[j] = row_min[j][i];
        get_min(a,b,n);
        
        for(int j = 1;j <= n;j++)a[j] = row_max[j][i];
        get_max(a,c,n);
        
        for(int j = k;j <= n;j++)res = min(c[j] - b[j],res);
    }
    cout << res << endl;
    return 0;
}