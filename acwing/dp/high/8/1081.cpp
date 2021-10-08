#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

typedef long long LL;

#define pb  push_back
#define fi first
#define se second
#define rep1(c,a,b) for(int c = a;c < b;++c)
#define rep2(c,a,b) for(int c = a;c <= b;++c)
#define repx(a,b) for(int a = h[b];~a;a = ne[a])
#define mf(h) memset(h,-1,sizeof h);
#define ALL(a) a.begin(),a.end()

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

const int N = 35,M = 22,K = 110;
const int MOD18 = 1e8,INF = 0x3f3f3f3f;
const double eps = 1e-8;

int n,m,k,b;
int f[N][N];

void init(){
    //预处理
    //i位选择j个1
    for(int i = 0; i < N;i++)f[i][0] = 1;//一个也不选也是一种方案
    for(int i = 1;i < N;i++){
        for(int j = 1;j < N;j++){
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }
    }
}

int solve(int u){
    VI nums;
    if(u == 0)return 0;
    while (u){
        nums.pb(u % b);
        u /= b;
    }
    int ans = nums.size();
    int res = 0;
    int last = 0;
    for(int i = ans - 1;i >= 0;i--){
        int x = nums[i];
        if(x)res += f[i][k - last];
        if(x){
            if(x > 1){
                if(k - last - 1 >= 0)res += f[i][k - last - 1];
                break;
            }else last++;
        }
        if(last > k)break;
        if(!i && k == last)res++;
    }
    return res;
}

int main(){
    init();
    scanf("%d%d%d%d",&n,&m,&k,&b);
    printf("%d",solve(m) - solve(n - 1));

    return 0;
}