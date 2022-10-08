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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;


int n;
int cnt[N];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        cnt[x]++;
    }
    for(int i = 1;i <= 1e5;i++){
        if(cnt[i] % 2 == 1){
            cout << "Conan" << endl;
            return 0;
        }
    }
    cout << "Agasa" << endl;
    return 0;
}