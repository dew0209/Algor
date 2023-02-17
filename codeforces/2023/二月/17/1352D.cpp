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

const int N = 2010,MOD = 1e9 + 7;

int n;
int q[N];

void solve(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&q[i]);
    }
    int sum = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int l = 1,r = n;
    while(l <= r){
        while(c <= d && l <= r){
            c += q[l++];
        }
        a += c;
        sum++;
        if(l > r)break;
        d = 0;
        while(c >= d && l <= r){
            d += q[r--];
        }
        b += d;
        sum++;
        if(l > r)break;
        c = 0;
    }
    printf("%d %d %d",sum,a,b);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}