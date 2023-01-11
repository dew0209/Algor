#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int q[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)scanf("%d",&q[i]);
    for(int i = 1;i <= n;i++)q[i] += q[i - 1];
    while(m--){
        int a,b;scanf("%d%d",&a,&b);
        printf("%d\n",q[b] - q[a - 1]);
    }
    return 0;
}