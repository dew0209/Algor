#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 100010;

void solve(){
    int n;cin >> n;
    int last = -1;
    LL ans = 0;
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        if(x < last){
            ans += last - x;
        }
        last = x;
    }
    cout << ans;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}