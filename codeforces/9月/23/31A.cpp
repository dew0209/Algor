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

const int N = 10010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
int q[N];
int cnt[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                if(i != j && i != k && j != k && q[i] == q[j] + q[k]){
                    cout << i << ' ' << j << ' ' << k << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}