#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int a[N];

void solve(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    int idx = 0;
    for(int i = 1;i < n;i++){
        if(a[i] < a[i - 1]){
            cnt++;
            idx = i;
        }
    }
    if(cnt == 1 && a[n - 1] <= a[0])cout << n - idx;
    else if(cnt == 0) cout << 0;
    else cout << -1;
}

int main(){
    int T = 1;//cin >> T;
    while(T--)solve(),puts("");
    return 0;
}