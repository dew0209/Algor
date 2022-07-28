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

int q[110];

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)cin >> q[i];
    int sum = 0;
    vector<int> count(110,0);
    for(int i = 0;i < n;i++){
        int d = sum + q[i] - m,k = 0;
        if(d > 0){
            for(int j = 100;j > 0;j--){
                int x = j * count[j];
                if(d <= x){
                    k += (d + j - 1) / j;
                    break;
                }
                k += count[j];
                d -= x;
            }
        }
        sum += q[i];
        count[q[i]]++;
        cout << k << ' ';
    }
}

int main(){
    solve();

    return 0;
}