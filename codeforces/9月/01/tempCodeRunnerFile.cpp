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

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,m;
int p[N],c[N];

int main(){
    cin >> n;
    int res = 0;
    for(int i = 2;i <= n;i++)cin >> p[i];
    for(int i = 1;i <= n;i++){
        cin >> c[i];
        c[p[i]] == c[i] ? 0 : ++res;
    }
    cout << res << endl;
}