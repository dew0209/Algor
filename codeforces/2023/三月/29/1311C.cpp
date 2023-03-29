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

const int N = 110,M = 200010;

int n,m;
int cnt[26];
int ans[M];

void insert(int x,int i,int j){
    ans[i] += x;
    ans[j] -= x;
}

void solve(){
    memset(cnt,0,sizeof cnt);
    memset(ans,0,sizeof ans);
    scanf("%d%d",&n,&m);
    string s;cin >> s;
    for(int i = 0;i < m;i++){
        int c;scanf("%d",&c);
        insert(1,0,c);
    }
    for(int i = 1;i < n;i++){
        ans[i] += ans[i - 1];
    }
    for(int i = 0;i < n;i++){
        int t = s[i] - 'a';
        cnt[t] += ans[i] + 1;
    }
    for(int i = 0;i < 26;i++){
        printf("%d ",cnt[i]);
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}