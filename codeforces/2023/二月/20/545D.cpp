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

const int N = 100010,MOD = 1e9 + 7;

int n;
int q[N],p[N];

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
        p[i] = q[i];
    }
    sort(q,q + n);
    int sum = 0;
    LL count = 0;
    for(int i = 0;i < n;i++){
        if(q[i] >= count){
            sum++;
            count += q[i];
        }
    }
    printf("%d\n",sum);
    return 0;
}