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

const int N = 1000010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
int q[N];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> q[i];
    int x = INF;
    int res = 0;
    for(int i = n - 1;i >= 0;i--){
        if(i < x)res++;
        x = min(x,i - q[i]);
    }
    cout << res << endl;
    return 0;
}