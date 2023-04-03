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
 
const int N = 200010,M = 200010;

int n,m;

int main(){
    scanf("%d%d",&n,&m);
    if(n == 1 && m == 1)printf("1\n");
    else {
        if(n > 2 * m - 1)printf("%d\n",m + 1);
        else printf("%d\n",m - 1);
    }
    return 0;
}