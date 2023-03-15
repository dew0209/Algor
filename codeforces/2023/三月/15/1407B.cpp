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

const int N = 1010;

int n;
int q[N];
int f[N];

int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}

void solve(){
    scanf("%d",&n);
    int mi = 0;
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
        if(q[i] > q[mi]){
            mi = i;
        }
    }
    f[0] = q[mi];
    q[mi] = 0;
    int cg = f[0];
    for(int i = 1;i < n;i++){
        int ci = 0;
        int cans = 0;
        for(int j = 0;j < n;j++){
            if(q[j] && gcd(cg,q[j]) > cans){
                ci = j;
                cans = gcd(cg,q[j]);
            }
        }
        f[i] = q[ci];
        cg = cans;
        q[ci] = 0;
    }
    for(int i = 0;i < n;i++){
        printf("%d ",f[i]);
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}