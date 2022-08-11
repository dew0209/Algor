#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7;

int n;
int q[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
        q[i] += q[i - 1];
    }
    int ans = 0;
    for(int i = 1;i < n;i++){
        if(q[i] == q[n] - q[i]){
            ans++;
        }
    }
    cout << ans << endl;
}