#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#define fi first
#define se second

using namespace std;

const int N = 100010;

int n,m;

void solve(){
    map<int,int> cnt;
    cin >> n;
    int ans = 0;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        while(c % 2 == 0){
            if(!cnt.count(c)){
                ans++;
                cnt[c] = 1;
            }
            c /= 2;
        }
    }
    cout << ans;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}