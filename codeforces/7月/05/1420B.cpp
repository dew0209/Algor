#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 100010;



void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++)cin >> a[i];
    LL ans = 0;
    for(int j = 29;j >= 0;j--){
        LL cnt = 0;
        for(int i = 0;i < n;i++){
            if(a[i] >= (1 << j) && a[i] < (1 << (j + 1))){
                cnt++;
            }
        }
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans;
}


int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}