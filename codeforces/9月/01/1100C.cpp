#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

const double PI = acos(-1);

int main(){
    double n,r;
    cin >> n >> r;
    double sinVal = sin(PI / n);
    double res = (sinVal * r) / (1 - sinVal);
    printf("%.8lf",res);
}