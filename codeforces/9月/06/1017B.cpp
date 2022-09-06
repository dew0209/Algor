#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n;
LL cnt[4];
int c1[4] = {'0','0','1','1'};
int c2[4] = {'0','1','0','1'};

//00 * 10 + 10 * 01 + 00 * 11

int main(){
    cin >> n;
    string s1,s2;cin >> s1 >> s2;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 4;j++){
            if(c1[j] == s1[i] && c2[j] == s2[i]){
                cnt[j]++;
            }
        }
    }
    cout << cnt[0] * cnt[2] + cnt[2] * cnt[1] + cnt[0] * cnt[3] << endl;

    return 0;
}