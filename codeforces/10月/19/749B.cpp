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

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int main(){
    int a,x;
    int b,y;
    int c,z;
    cin >> a >> x >> b >> y >> c >> z;
    cout << 3 << endl;
    cout << b + c - a << ' ' << y + z - x << endl;
    cout << a + c - b << ' ' << x + z - y << endl;
    cout << a + b - c << ' ' << x + y - z << endl;
    return 0;
}