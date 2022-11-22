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
map<int,int> q;
int s[N];

void init(){
    for(int i = 1;i < N;i++)
        q[i] = 0;
}

void solve(){
    init();
    cin >> n;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        s[i] = c;
        q[c]++;
    }
    LL res = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == 0){
            int sum = q[0 - s[i]];
            if(sum != 0){
                res += sum - 1;
            }
        }else {
            res += q[0 - s[i]];
        }
        q[s[i]]--;
        //cout << res << endl;
    }
    cout << res;
}

int main(){
    int T = 1;
    while(T--)solve(),puts("");
    return 0;
}