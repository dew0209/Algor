#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

using namespace std;

const int N = 200010;

void solve(){
    int n,k;scanf("%d%d",&n,&k);
    int minv = 1e9;
    for(int i = 1;i <= k / i;i++){
        if(n % i == 0){
            minv = min(minv,min(n / i));
        }
    }
    printf("%d",minv);
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--)solve(),puts("");
    return 0;
}