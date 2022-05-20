#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200010,MAX_V = 0x3f3f3f3f;

int n;

void solve(){
    cin >> n;
    vector<int> ans(n);
    for(int i = 0;i < n;i++)cin >> ans[i];
    sort(ans.begin(),ans.end());
    int pos = -1,mn = MAX_V;
    if(n == 2){
        cout << ans[0] << ' ' << ans[1];
        return;
    }
    for(int i = 0;i < n - 1;i++){
        if(mn > ans[i + 1] - ans[i]){
            pos = i;
            mn = ans[i + 1] - ans[i];
        }
    }

    for(int i = pos + 1;i < n;i++){
        cout << ans[i] << ' ';
    }
    for(int i = 0;i <= pos;i++){
        cout << ans[i] << ' ';
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}