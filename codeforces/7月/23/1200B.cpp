#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m,k;

void solve(){
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    bool ok = true;
    for(int i = 0;i < n - 1;i++){
        int minv = max(0,a[i + 1] - k);
        if(minv <= a[i]){
            m += a[i] - minv;
        }else {
            m -= minv - a[i];
        }
        if(m < 0){
            ok = false;
            break;
        }
    }
    if(ok)cout << "YES";
    else cout << "NO";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}