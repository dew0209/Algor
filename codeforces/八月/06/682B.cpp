#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
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
    for(int i = 0;i < n;i++)cin >> q[i];
    int res = 1;
    sort(q,q + n);
    for(int i = 0;i < n;i++){
        if(res <= q[i]){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}