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

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
int res[N];

bool check(int u){
    int sum = u;
    while(u){
        sum += u % 10;
        u /= 10;
    }
    return sum == n;
}

int main(){
    cin >> n;
    int idx = 0;
    for(int i = n - 100;i <= n;i++){
        if(check(i)){
            res[idx++] = i;
        }
    }
    cout << idx << endl;
    for(int i = 0;i < idx;i++){
        cout << res[i] << ' ';
    }
    cout << endl;
}