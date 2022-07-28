#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7;

/**
 * n * n - szY·n - szX·n + szX·szY
 * n * ( n - szy) - szX(n - szY)
 * (n - szX)(n - szY)
 */
int n,m;
int a[N],b[N];

int main(){
    cin >> n >> m;
    LL v = n,w = n;
    for(int i = 0;i < m;i++){
        int x,y;cin >> x >> y;
        v -= !a[x]++;
        w -= !b[y]++;
        cout << v * w << ' ';
    }
}