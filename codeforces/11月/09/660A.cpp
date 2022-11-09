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

int get_gcd(int a,int b){
    return b ? get_gcd(b,a % b) : a;
}

int q[N];

int main(){
    int n;cin >> n;
    vector<int> res;
    for(int i = 0;i < n;i++)cin >> q[i];
    int last = 1;
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(get_gcd(last,q[i]) != 1){
            res.push_back(1);
            ans++;
        }
        res.push_back(q[i]);
        last = q[i];
    }
    cout << ans << endl;
    for(auto c : res){
        cout << c << ' ';
    }
    cout << endl;
    return 0;
}