#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200010;

typedef long long LL;

int n,m;

int main(){
    scanf("%d%d",&n,&m);
    vector<int> q;
    for(int i = 1;i <= n;i++){
        int c;scanf("%d",&c);
        if(c > n - m){
            q.push_back(i);
        }
    }
    LL res = (n + n - m + 1) * 1LL * m / 2;
    LL ans = 1;
    for(int i = 1;i < q.size();i++){
        ans = ans * (q[i] - q[i - 1]) % 998244353;
    }
    printf("%lld %lld\n",res,ans);
}