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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
int q[N];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> q[i];
    vector<pair<int,int>> res;
    for(int i = 0;i < n;i++){
        int j = i;
        for(int t = i;t < n;t++){
            if(q[j] > q[t]){
                j = t;
            }
        }
        if(i != j){
            res.push_back(make_pair(i,j));
            swap(q[i],q[j]);
        }
    }
    cout << res.size() << endl;
    for(auto c : res){
        cout << c.fi << ' ' << c.se << endl;
    }
    return 0;
}