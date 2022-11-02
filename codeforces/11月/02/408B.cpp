#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int cs[26];
int ct[26];

int main(){
    string s,t;cin >> s >> t;
    for(int i = 0;i < s.size();i++)cs[s[i] - 'a']++;
    for(int i = 0;i < t.size();i++)ct[t[i] - 'a']++;
    int res = 0;
    for(int i = 0;i < 26;i++){
        if(ct[i] != 0 && cs[i] == 0){
            res = -1;
            break;
        }
        res += min(cs[i],ct[i]);
    }
    if(res == 0)res = -1;
    cout << res << endl;
    return 0;
}