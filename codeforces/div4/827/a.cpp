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

void solve(){
    int a,b,c;cin >> a >> b >> c;
    if(a == b + c || b == a + c || c == a + b){
        cout << "YES";
    }else {
        cout << "NO";
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}