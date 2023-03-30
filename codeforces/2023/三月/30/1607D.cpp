#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <sstream>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
 
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,LL> PIL;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;
 
const int N = 1010,M = 200010;
 
int n,m;
int q[M];

void solve(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    string s;cin >> s;
    vector<int> a;
    vector<int> b;
    for(int i = 0;i < n;i++){
        if(s[i] == 'B'){
            a.pb(q[i]);
        }else {
            b.pb(q[i]);
        }
    }
    int ok = 1;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i = 0;i < a.size();i++){
        if((i + 1) > a[i]){
            ok = 0;
        }
    }
    int ed = n;
    for(int i = b.size() - 1;i >= 0;i--){
        if((ed--) < b[i]){
            ok = 0;
        }
    }
    if(ok)printf("Yes");
    else printf("No");
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}