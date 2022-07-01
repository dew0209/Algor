//https://codeforces.com/contest/1409/problem/C
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int ans[N];

void solve(){
    cin >> n;
    int x,y;cin >> x >> y;
    int diff = 0;
    bool ok = false;
    for(int i = n;i >= 1;i--){
        for(int j = 1;j < i;j++){
            if((y - x) % (i - j) == 0){
                diff = (y - x) / (i - j);
                if(x - diff * (j - 1) > 0){
                    ans[i] = y;
                    for(int k = i + 1;k <= n;k++){
                        ans[k] = ans[k - 1] + diff;
                    }
                    for(int k = i - 1;k >= 1;k--){
                        ans[k] = ans[k + 1] - diff;
                    }
                    ok = true;
                    break;
                }
            }
        }
        if(ok)break;
    }
    
    for(int i = 1;i <= n;i++){
        cout << ans[i] << ' ';
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}