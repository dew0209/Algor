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
int cnt[N];

int main(){
    cin >> n;
    int m = 0;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        cnt[c]++;
        m = max(cnt[c],m);
    }
    cout << n - m << endl;
}