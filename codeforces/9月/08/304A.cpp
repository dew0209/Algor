#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;

int main(){
    cin >> n;
    int res = 0;
    for(int i = 1;i < n;i++){
        for(int j = i + 1;j <= n;j++){
            double k = sqrt(i * i + j * j);
            if(k == (int)k && k <= n && (k * k) == (i * i + j * j)){
                //cout << i << ' ' << j << ' ' << k << ' ' << k * k << endl;
                res++;
            }
        }
    }
    cout << res << endl;

    return 0;
}