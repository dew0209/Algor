#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200010;

typedef long long LL;


int n;
int q[N];
int res[N];

void solve(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    for(int i = 1;i < n;i++){
        int t = q[i];
        int now = q[i] | q[i - 1];
        res[i] = now - t;
        q[i] = q[i] ^ res[i];
    }
    for(int i = 0;i < n;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
}


int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}