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

int main(){
    int n,m;cin >> n >> m;
    map<int,int> cnt;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        cnt[c] = 1;
    }
    vector<int> res;
    for(int i = 1;i <= m;i++){
        if(!cnt[i]){
            res.push_back(i);
            m -= i;
        }
    }
    cout << res.size() << endl;
    for(int i = 0;i < res.size();i++){
        cout << res[i] << ' ';
    }
    cout << endl;
}