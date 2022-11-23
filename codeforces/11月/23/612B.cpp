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

const int N = 200010;

int q[N];

int main(){
    int n;cin >> n;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        q[c] = i + 1;
    }
    LL res = 0;
    for(int i = 2;i <= n;i++){
        res += abs(q[i] - q[i - 1]);
    }
    cout << res << endl;
    return 0;
}