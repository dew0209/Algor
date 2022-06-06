#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010;
int a[N],b[N];

void solve(){
    int n;cin >> n;
    int idx1 = 1,idx2 = 1;
    for(int i = 1;i <= 2 * n;i++){
        int x,y;cin >> x >> y;
        if(x == 0)b[idx2++] = abs(y);
        if(y == 0)a[idx1++] = abs(x);
    }
    sort(a + 1,a + n + 1);
    sort(b + 1,b + n + 1);
    double res = 0;
    for(int i = 1;i <= n;i++){
        res += sqrt(1.0 * a[i] * a[i] + 1.0 * b[i] * b[i]);
    }
    printf("%.15f",res);
}

int main(){
    int T;scanf("%d",&T);
    while(T--)solve(),puts("");

    return 0;
}