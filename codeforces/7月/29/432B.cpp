#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7;

int n;
int x[N],y[N];
int cnt[N];
int ans_x[N];
int ans_y[N];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> x[i] >> y[i];
        cnt[x[i]]++;
    }
    for(int i = 0;i < n;i++){
        ans_x[i] = n - 1;
        ans_x[i] += cnt[y[i]];
        ans_y[i] = 2 * (n - 1) - ans_x[i];
    }
    for(int i = 0;i < n;i++){
        cout << ans_x[i] << ' ' << ans_y[i] << endl;
    }
}