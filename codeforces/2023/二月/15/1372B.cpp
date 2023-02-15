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

const int N = 510;

using namespace std;

void solve(){
    int n;scanf("%d",&n);
    int key = n;
    for(int i = 2;i <= n / i;i++){
        if(n % i == 0){
            key = i;
            break;
        }
    }
    printf("%d %d",n / key,n - n / key);
}


int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}