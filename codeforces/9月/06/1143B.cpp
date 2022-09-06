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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int f(int n){
    if(n < 10)return max(1,n);
    return max((n % 10) * f(n / 10),9 * f(n / 10 - 1));
}

int main(){
    int n;cin >> n;
    cout << f(n) << endl;
    return 0;
}