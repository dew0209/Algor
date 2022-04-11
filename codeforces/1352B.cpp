//https://codeforces.com/problemset/problem/1352/B
#include <iostream>

using namespace std;

const int N = 110;

int n,m;

void solve(){
    cin >> n >> m;
    if(n % 2 == 0 && m % 2 == 1){
        //偶数组成
        //k - 1 个 2 + 剩下的
        int cnt = (m - 1) * 2;
        int ans = n - cnt;
        if(ans % 2 == 0 && ans > 0){
            cout << "Yes" << endl;
            for(int i = 1;i <= m;i++){
                if(i != m)cout << 2 << ' ';
                else cout << ans << endl; 
            }
        }else {
            cout << "No" << endl;
        }
    }
    if(n % 2 == 0 && m % 2 == 0){
        //奇数和偶数都可以组成
        //偶数组成
        //k - 1 个 2 + 剩下的
        int cnt = (m - 1) * 2;
        int ans = n - cnt;
        if(ans % 2 == 0 && ans > 0){
            cout << "Yes" << endl;
            for(int i = 1;i <= m;i++){
                if(i != m)cout << 2 << ' ';
                else cout << ans << endl; 
            }
            return;
        }
        //奇数组成
        cnt = m - 1;
        ans = n - cnt;
        if(ans % 2 == 1 && ans > 0){
            cout << "Yes" << endl;
            for(int i = 1;i <= m;i++){
                if(i != m)cout << 1 << ' ';
                else cout << ans << endl; 
            }
        }else {
            cout << "No" << endl;
        }
        return;
    }
    if(n % 2 == 1 && m % 2 == 0){
        //无解
        cout << "No" << endl;
        return;
    }
    if(n % 2 == 1 && m % 2 == 1){
        //奇数组成
        int cnt = m - 1;
        int ans = n - cnt;
        if(ans % 2 == 1 && ans > 0){
            cout << "Yes" << endl;
            for(int i = 1;i <= m;i++){
                if(i != m)cout << 1 << ' ';
                else cout << ans << endl; 
            }
        }else {
            cout << "No" << endl;
        }
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}