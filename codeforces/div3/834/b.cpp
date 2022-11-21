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

const int N = 110;
int q[N];
int s[N];

void solve(){
    int n,m;cin >> n >> m;
    int maxv = 0;
    int sumv = 0;
    for(int i = 1;i <= n;i++){
        cin >> s[i];
        maxv = max(maxv,s[i]);
        sumv += s[i];
    }
    m = m - (q[maxv] - sumv);
    for(int i = maxv + 1;i <= 101;i++){
        if(m == 0){
            cout << "YES";
            return;
        }else if(m < i){
            cout << "NO";
            return;
        }else {
            m -= i;
        }
    }
}

int main(){
    for(int i = 1;i <= 101;i++){
        q[i] = i;
        q[i] += q[i - 1];
    }
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}