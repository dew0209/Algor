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

int n;

void solve(){
    scanf("%d",&n);
    vector<int> ans(20,0);
    for(int i = 0;i < n;i++){
        int c;scanf("%d",&c);
        ans[c % 10]++;
    }
    vector<int> v;
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < min(ans[i],3);j++){
            v.pb(i);
        }
    }
    int ok = 0;
    for(int i = 0;i < v.size();i++){
        for(int j = i + 1;j < v.size();j++){
            for(int k = j + 1;k < v.size();k++){
                if((v[i] + v[j] + v[k]) % 10 == 3){
                    ok = 1;
                    break;
                }
            }
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