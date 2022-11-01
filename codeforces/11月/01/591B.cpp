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

int cnt[26];

int main(){
    int n,m;cin >> n >> m;
    string s;cin >> s;
    for(int i = 0;i < 26;i++)cnt[i] = i;
    while(m--){
        char a,b;cin >> a >> b;
        int d1 = a - 'a';
        int d2 = b - 'a';
        for(int i = 0;i < 26;i++){
            if(cnt[i] == d1){
                cnt[i] = d2;
            }else if(cnt[i] == d2){
                cnt[i] = d1;
            }
        }
    }
    for(int i = 0;i < n;i++){
        int idx = s[i] - 'a';
        s[i] = (char)(cnt[idx] + 'a');
    }

    cout << s << endl;

    return 0;
}