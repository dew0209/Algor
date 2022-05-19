#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 100010;

int n;
LL q[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
    }
    //a[i] * a[j] = i + j
    //固定a[i]
    //i+j是a[i]的倍数 设k倍
    //k * a[i] = i + j
    //j = k * a[i] - i
    LL ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = q[i] - i;j <= n;j += q[i]){
            if(j <= i)continue;
            if(q[i] * q[j] == i + j){
                ans++;
            }
        }
    }
    cout << ans;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}