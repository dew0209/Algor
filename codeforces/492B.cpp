#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int  N = 100010;
 
int n,m;
int g[N];
double cnt[N];
 
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> g[i];
    g[n + 1] = m;
    sort(g + 1,g + 1 + n);
    for(int i = 1;i <= n + 1;i++){
        cnt[i] = g[i] - g[i - 1];
    }
    double res = 0;
    for(int i = 1;i <= n + 1;i++){
        if(i == 1 || i == n + 1){
            if(cnt[i] > res)res = cnt[i];
        }else {
            if(cnt[i] / 2 > res)res = cnt[i] / 2;
        }
    }
    printf("%.9f",res);
    return 0;
}