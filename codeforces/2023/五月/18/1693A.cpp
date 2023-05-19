#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

typedef long long LL;

const int N = 200010;

int n;
LL sum[N];
int q[N];

void solve(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
        sum[i] = q[i] + sum[i - 1];
    }
    int ok = 1;
    if(sum[n] != 0)ok = 0;

    for(int i = 1;i <= n;i++){
        if(sum[i] < 0)ok = 0;
    }

    int fl = 0;

    for(int i = 1;i <= n;i++){
        if(sum[i] == 0)fl = 1;
        else if(fl){
            ok = 0;
        }
    }
    if(ok)puts("Yes");
    else puts("No");
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve();

    return 0;
}