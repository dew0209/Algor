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
const LL maxL = 2e12;

vector<string> cnt;
string s;

int get_res(string s,string t){
    int tol = 0;
    int j = 0;
    for(int i = 0;i < s.size() && j < t.size();i++){
        if(s[i] == t[j]){
            j++;
            tol++;
        }
    }
    return s.size() + t.size() - 2 * tol;
}

void solve(){
    cin >> s;
    int ans = s.size() + 1;
    for(auto t : cnt){
        ans = min(ans,get_res(s,t));
    }
    printf("%d",ans);
}

int main(){
    int t;scanf("%d",&t);
    for(LL i = 1;i <= maxL;i *= 2){
        cnt.pb(to_string(i));
    }
    while(t--)solve(),puts("");
    return 0;
}