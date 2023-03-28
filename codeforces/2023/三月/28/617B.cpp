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

const int N = 110;

int n;
int q[N];

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    LL res = 0;
    int last = -1;
    for(int i = 0;i < n;i++){
        if(q[i] == 1){
            if(last == -1){
                res = 1;
            }else {
                res = res * (i - last);
            }
            last = i;
        }
    }
    printf("%lld\n",res);
    return 0;
}