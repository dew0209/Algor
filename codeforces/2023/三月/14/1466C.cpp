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

const int N = 100010;

void solve(){
    string s;cin >> s;
    int n = s.size();
    vector<int> f(n + 10,0);
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(i - 1 >= 0 && s[i] == s[i - 1] && f[i - 1] == 0){
            ans++;
            f[i] = 1;
        }
        if(i - 2 >= 0 && s[i] == s[i - 2] && f[i - 2] == 0){
            ans++;
            f[i] = 1;
        }
    }
    printf("%d",ans);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
}