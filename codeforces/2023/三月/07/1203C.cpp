#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,LL> PIL;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;

const int N = 100010;

int n;
int q[N];

LL gcd(LL a,LL b){
    return b ? gcd(b,a % b) : a;
}

int main(){
    scanf("%lld",&n);
    LL x = 1;
    for(int i = 0;i < n;i++){
        LL c;scanf("%lld",&c);
        if(i == 0){
            x = c;
        }else {
            x = gcd(x,c);
        }
    }
    LL ans = 0;
    for(int i = 1;i <= x * 1LL / i;i++){
        if(x % i == 0){
            ans = ans + 1;
            if(x / i != i){
                ans = ans + 1;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}