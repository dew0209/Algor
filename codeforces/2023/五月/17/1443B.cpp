#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200010;

int a,b;
char c[N];
int f[N];
int sum[N];

void solve(){

    memset(f,0,sizeof f);
    memset(sum,0,sizeof sum);

    scanf("%d%d",&a,&b);
    cin >> c + 1;

    int len = strlen(c + 1);

    for(int i = 1;i <= len;i++)sum[i] = sum[i - 1] + (c[i] == '0');
    int miv = 0;
    for(int i = 1;i <= len;i++){
        if(c[i] == '0'){
            f[i] = f[i - 1];
        }else {
            f[i] = miv + sum[i] * b + a;
        }
        miv = min(miv,f[i] - sum[i] * b);
    }
    printf("%d\n",f[len]);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();

    return 0;
}