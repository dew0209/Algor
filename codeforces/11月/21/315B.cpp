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

const int N = 100010;

int n,m;
int q[N];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> q[i];
    int s = 0;
    while(m--){
        int query;cin >> query;
        int x,y;
        if(query == 1){
            cin >> x >> y;
            q[x] = y - s;
        }else if(query == 2){
            cin >> x;
            s += x;
        }else {
            cin >> x;
            cout << q[x] + s << endl;
        }
    }
    return 0;
}