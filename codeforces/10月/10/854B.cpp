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

int n,k;

int main(){
    cin >> n >> k;
    if(k == 0 || n == k){
        cout << "0 0" << endl;
    }else {
        cout << "1 " << min(n - k,k << 1) << endl;
    }

    return 0;
}