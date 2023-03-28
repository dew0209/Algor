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

const int N = 110;

int n,m;
int q[N];
int st[N];

void solve(){
    scanf("%d",&n);
    vector<int> a;
    for(int i = 0;i < n;i++){
        scanf("%d",&q[i]);
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&st[i]);
        if(!st[i]){
            a.pb(q[i]);
        }
    }
    sort(a.begin(),a.end());
    int j = 0;
    for(int i = a.size() - 1;i >= 0;){
        while(st[j])j++;
        q[j++] = a[i--];
    }
    for(int i = 0;i < n;i++){
        printf("%d ",q[i]);
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}