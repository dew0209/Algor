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

const int N = 1000010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int main(){
    string s;cin >> s;
    LL res = 0;
    string ans = "";
    string cnt = "><+-.,[]";
    for(int i = 0;i < s.size();i++){
        for(int j = 0;j < 8;j++){
            if(s[i] == cnt[j]){
                res = (res * 16 + (8 + j)) % 1000003;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}