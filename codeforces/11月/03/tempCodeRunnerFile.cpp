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

int n,m;

int main(){
    cin >> n >> m;
    if(m >= n){
        cout << -1 << endl;
        return 0;
    }
    cout << n - m << ' ';
    for(int i = 0;i < m - 1;i++){
        cout << i + 1 << ' ';
    }
    for(int i = m;i < n;i++){
        cout << i + 1 << ' ' ;
    }
    cout << endl;

    return 0;
}