#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,q;

void solve(){
    cin >> n >> q;
    int st1 = 0;
    int st2 = 0;
    LL sum = 0;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        if(c % 2 == 1){
            st1++;
        }else {
            st2++;
        }
        sum += c;
    }
    while(q--){
        int x,y;cin >> x >> y;
        //处理偶数
        if(x == 0){
            sum += y * st2;
            //偶数 + 奇数 = 奇数
            if(y % 2 == 1){
                st1 += st2;
                st2 = 0;
            }
        }else {
            sum += y * st1;
            if(y % 2 == 1){
                st2 += st1;
                st1 = 0;
            }
        }
        //cout << "ans ";
        cout << sum << endl;
    }
    
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}