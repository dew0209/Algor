#include <iostream>
#include <cstring>
#include <algorithm>


typedef long long LL;

using namespace std;

const int N = 200010;

int n,m;
LL q[N];

int get_ans(){
    LL sum = 0;
    for(int i = 1;i <= n + 1;i++)sum += q[i];
    if(sum == q[n + 1] * 2)return n + 1;
    for(int i = 1;i <= n + 1;i++)
        if(sum == q[n + 2] + q[i])return i;
    return 0;
}

void solve(){
    cin >> n;
    for(int i = 1;i <= n + 2;i++)cin >> q[i];
    sort(q + 1,q + n + 3);
    if(m = get_ans()){
        for(int i = 1;i <= n + 1;i++){
            if(i != m)cout << q[i] << ' ';
        }
    }else cout << -1;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}