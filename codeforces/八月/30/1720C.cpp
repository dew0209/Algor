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

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,m;
int q[510][510];

void solve(){
    cin >> n >> m;
    string s;
    int sum = 0;
    for(int i = 0;i < n;i++){
        cin >> s;
        for(int j = 0;j < m;j++){
            q[i][j] = s[j] - '0';
            sum += q[i][j];
        }
    }
    int minv = INF;
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j < m - 1;j++){
            int count = q[i][j] + q[i + 1][j] + q[i + 1][j + 1] + q[i][j + 1];
            if(count == 0)continue;
            minv = min(minv,max(1,count - 1));
        }
    }
    if(sum == 0)cout << "0";
    else cout << 1 + sum - minv;

}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}