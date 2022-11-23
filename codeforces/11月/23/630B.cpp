#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;


#define fi first
#define se second

using namespace std;

const int N = 200010;

int main(){
    int n,m;cin >> n >> m;
    double res = 1.000000011;
    double ans = n;
    
    printf("%.8lf\n",ans * pow(res,m));
    return 0;
}