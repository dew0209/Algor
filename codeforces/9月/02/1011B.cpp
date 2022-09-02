#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 100,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,m;

int main(){
    cin >> n >> m;
    vector<int> a(N + 1);
    for(int i = 0;i < m;i++){
        int c;cin >> c;
        a[c]++;
    }
    for(int i = 100;i >= 1;i--){
        vector<int> cc(a);
        int k = 0;
        for(int j = 1;j <= 100;j++){
            while(cc[j] >= i){
                k++;
                cc[j] -= i;
            }
        }
        if(k >= n){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}