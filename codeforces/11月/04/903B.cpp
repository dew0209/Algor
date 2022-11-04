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

int q[10010];

int main(){
    int n,a,b,c,d;cin >> n >> a >> b >> c >> d;
    while(c > 0){
        if(n > d || c <= a){
            q[++q[0]] = 0;
            c -= a;
        }else {
            n += b;
            q[++q[0]] = 1;
        }
        n -= d;
    }
    cout << q[0] << endl;
    for(int i = 1;i <= q[0];i++)cout << (q[i] ? "HEAL" : "STRIKE") << endl;
    return 0;
}