#include <iostream>
#include <cstring>
#include <vector>
#include <numeric>

typedef long long LL;

using namespace std;

const int N = 100010;

LL n,m;

void solve(){
    cin >> n >> m;
    n = n / m;
    vector<int> dist(10);
    for(int i = 0;i < 10;i++){
        dist[i] = ((i + 1) * m) % 10;
    }
    LL ans = 0;
    for(int i = 0;i < n % 10;i++)ans += dist[i];
    cout << ans + n / 10 * accumulate(dist.begin(),dist.end(),0LL);
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}