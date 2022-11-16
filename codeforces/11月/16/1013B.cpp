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
int cnt[N];
int sum[N];

int main(){
    int n,m;cin >> n >> m;
    int ans = 0x3f3f3f3f;
    for(int i = 0;i < n;i++){
        cin >> q[i];
        cnt[q[i]]++;
        if(cnt[q[i]] == 2){
            ans = 0;
        }
    }
    if(ans == 0){
        cout << 0 << endl;
        return 0;
    }
    //check 1
    for(int i = 0;i < n;i++){
        cnt[q[i]]--;
        int x = q[i] & m;
        //cout << "check 1 " << x << endl;
        if(cnt[x]){
            cout << 1 << endl;
            return 0;
        }
         cnt[q[i]]++;
    }
    //check -1
    bool ok = false;
    for(int i = 0;i < n;i++){
        int x = q[i] & m;
        sum[x]++;
        if(sum[x] == 2){
            ok = true;
        }
    }
    if(!ok){
        cout << -1 << endl;
    }else {
        cout << 2 << endl;
    }
    return 0;
}