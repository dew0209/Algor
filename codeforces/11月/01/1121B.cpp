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
int q[N];
int cnt[N];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> q[i];
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            cnt[q[i] + q[j]]++;
        }
    }
    sort(cnt + 1,cnt + 200002);
    cout << cnt[200001] << endl;
    return 0;
}