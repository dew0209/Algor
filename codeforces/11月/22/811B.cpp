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

const int N = 200010;

int n,m;
int q[N];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> q[i];
    while(m--){
        int l,r,x;cin >> l >> r >> x;
        int s = 0;
        for(int i =l;i <= r;i++){
            if(q[i] < q[x])s++;
        }
        cout << (l + s == x ? "Yes" : "No") << endl;
    }
    return 0;
}