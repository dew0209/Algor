//https://codeforces.com/problemset/problem/1363/A
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;

void solve(){
    cin >> n >> m;
    int odd = 0,even = 0;
    for(int i = 1;i <= n;i++){
        int c;cin >> c;
        if(c % 2)odd++;
        else even++;
    }
    //三种情况  要求结果为奇数，那么奇数 和 偶数 都要有 奇数的个数是奇数个
    //奇数 + 奇数 = 偶数
    //奇数 + 偶数 = 奇数
    //偶数 + 偶数 = 偶数
    
    //如果奇数是奇数个（和为奇数)
    bool ok = 0;
    for(int i = 1;i <= odd && i <= m;i += 2){
        if(m - i <= even){
            ok = 1;
            break;
        }
    }
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}