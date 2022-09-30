#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 10010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
priority_queue <int> q;

int main(){
    cin >> n;
    int res = 0;
    int maxv = 0;
    for(int i = 1;i <= n;i++){
        int c;cin >> c;
        if(i != 1)q.push(c);
        else res = c;
    }
    int ans = 0;
    while(res <= q.top()){
        int c = q.top();
        q.pop();
        res++;
        ans++;
        c--;
        q.push(c);
    }
    cout << ans << endl;
}