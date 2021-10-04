/*
 * 最佳牛围栏
 */
#include <iostream>

using namespace std;

const int N = 100010;

int n,m;
int g[N];
double sum[N];

bool check(double mid){
    for(int i = 1;i <= n;i++)
        sum[i] = sum[i - 1] + g[i] - mid;
    double mi = 0;
    for(int i = m,j = 0;i <= n;i++,j++){
        mi = min((double)sum[j],mi);
        if(sum[i] >= mi)return true;
    }
    return false;
}

int main(){
    cin >> n >> m;
    double l = 0,r = 0;
    for(int i = 1;i <= n;i++)cin >> g[i],r = max(r,(double)g[i]);
    while (r - l > 1e-5){
        double mid = (l + r) / 2;
        if(check(mid))l = mid;
        else r = mid;
    }
    cout << (int)(r * 1000) << endl;

    return 0;
}