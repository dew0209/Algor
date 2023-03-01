#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

using namespace std;

const int N = 300010,MOD = 1e9 + 7;

int n;
string a,b;

void solve(){
    scanf("%d",&n);
    cin >> a >> b;
    vector<int> res;
    for(int i = 0;i < n;i++){
        if(a[i] != b[i]){
            res.pb(i + 1);
            res.pb(1);
            res.pb(i + 1);
        }
    }
    printf("%d ",res.size());
    for(int i = 0;i < res.size();i++){
        printf("%d ",res[i]);
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}