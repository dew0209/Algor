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

const int N = 26;

void solve(){
    string s;
    cin >> s;
    vector<int> cnt(26,0);
    int ans = 0;
    for(int i = 0;i < s.size();i++){
        if(cnt[s[i] - 'a']){
            ans += 2;
            for(int j = 0;j < N;j++){
                cnt[j] = 0;
            }
        }else {
            cnt[s[i] - 'a'] = 1;
        }
    }
    printf("%d",s.size() - ans);
}

int main(){
    int t;scanf("%d",&t);
    while(t--)solve(),puts("");
    return 0;
}