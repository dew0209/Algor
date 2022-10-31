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

int ca,cb,cc;
string s;

int main(){
    cin >> s;
    int ok = 0;
    for(auto c : s){
        if(c == 'a'){
            ok ^= cb;
            ok ^= cc;
            ca++;
        }else if(c == 'b'){
            ok ^= !ca;
            ok ^= cc;
            cb++;
        }else if(c == 'c'){
            ok ^= !ca;
            ok ^= !cb;
            cc++;
        }
        if(ok)break;
    }
    if((cc != ca && cc != cb) || ok)cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}