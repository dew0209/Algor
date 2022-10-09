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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int a,b,c;

int main(){
    cin >> a >> b >> c;
    int y = b + c - a >> 1;
    int z = c + a - b >> 1;
    int x = b + a - c >> 1;
    if(x < 0 || y < 0 || z < 0){
        cout << "Impossible" << endl;
        return 0;
    }
    if(x + y + z << 1 != a + b + c){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << x << ' ' << y << ' ' << z << endl;
    return 0;
}