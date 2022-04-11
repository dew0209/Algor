//https://codeforces.com/problemset/problem/1343/C 双指针（代码不够好看，好看的代码请看另一个版本）
#include <iostream>
#include <algorithm>
#include <cstring>

typedef long long LL;

using namespace std;

const int N = 200010;

int n;
int q[N];
int p[N];

void solve(){
    cin >> n;
    memset(p,-0x3f,sizeof p);
    for(int i = 1;i <= n;i++)cin >> q[i];
    int idx = 0;
    for(int i = 1;i <= n;idx++){
        if(q[i] < 0){
            while(q[i] < 0 && i <= n){
                p[idx] = max(p[idx],q[i]);
                i++;
            }
        }else {
            while(q[i] > 0 && i <= n){
                p[idx] = max(p[idx],q[i]);
                i++;
            }
        }
    }
    LL res = 0;
    for(int i = 0;i < idx;i++)res += p[i];
    
    cout << res << endl;
}

int main(){
    int T;cin >> T;
    while(T--){
        solve();
    }
    return 0;
}