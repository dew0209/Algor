#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

typedef long long LL;

using namespace std;

const int N = 100010;

int n;

int main(){
    cin >> n;
    LL ans = 0;
    for(int i = 2;i < n;i++){
        ans = ans + i * 1LL * (i + 1);
    }
    cout << ans << endl;
}