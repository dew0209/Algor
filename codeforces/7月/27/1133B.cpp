#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7;

int n,k;
int r[110];
int main(){
    cin >> n >> k;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        r[c % k]++;
    }
    int ans = 0;
    ans += r[0] / 2;
    for(int i = 1;i < k;i++){
        if(k - i <= i)break;
        //cout << r[i] << "===" << r[k - i] << endl;
        ans += min(r[i],r[k - i]);
    }
    if(k / 2 * 2 == k){
        ans += r[k / 2] / 2;
    }
    cout << ans * 2 << endl;
}