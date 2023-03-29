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

int n;
int p[N];
int st[N];
int res[N];

void solve(){
    memset(p,0,sizeof p);
    memset(st,0,sizeof st);
    memset(res,0,sizeof res);

    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&p[i]);
    }
    for(int i = j;j <= n;j++){
        if (!st[j]) {
				vector<int> cur;
				while (!st[j]) {
					cur.push_back(j);
					st[j] = true;
					j = p[j];
				}
				for (auto el : cur) res[el] = cur.size();
		}
    }
    for(int i = 1;i <= n;i++){
        printf("%d ",res[i]);
    }
}

int main(){

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}