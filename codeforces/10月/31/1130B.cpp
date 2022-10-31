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

int n;
int q[N];
int s1[N];
int s2[N];

int main(){
    cin >> n;
    int m = n * 2;
    for(int i = 1;i <= m;i++)cin >> q[i];
    for(int i = 1;i <= m;i++){
        if(s1[q[i]] == 0){
            s1[q[i]] = i;
        }else {
            s2[q[i]] = i;
        }
    }
    LL res = 0;
    int l1 = 1;
    int l2 = 1;
    for(int i = 1;i <= n;i++){
        res += 1LL * abs(s1[i] - l1);
        l1 = s1[i];
        res += 1LL * abs(s2[i] - l2);
        l2 = s2[i];
        //cout << i << "===" << s1[i] << ' ' << s2[i] << endl;
    }
    cout << res << endl;

    return 0;
}