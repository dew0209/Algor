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
priority_queue <int> que;
int q[N];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> q[i];
    int s = 0,res = 0;
    while(true){
        for(int i = 0;i < n;i++){
            if(q[i] <= s)q[i] = n + 1,s++;
        }
        if(s == n)break;
        res++;
        for(int i = n - 1;i >= 0;i--){
            if(q[i] <= s)q[i] = n + 1,s++;
        }
        if(s == n)break;
        res++;
    }
    cout << res << endl;
    return 0;
}