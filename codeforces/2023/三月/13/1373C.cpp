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
    LL res = 0;
    LL sum = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '+')sum += 1;
        else sum -= 1;
        if(sum < 0){
            sum = sum + 1;
            res = res + i + 1;
        }
    }
    printf("%lld",res + s.size());
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}