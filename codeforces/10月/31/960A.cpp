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
    int idx = -1;
    for(auto c : s){
        if(c == 'a'){
            if(idx > 0){
                ok = 1;
                break;
            }
            ok ^= cb;
            ok ^= cc;
            ca++;
            idx = 0;
        }else if(c == 'b'){
            if(idx > 1){
                ok = 1;
                break;
            }
            ok ^= !ca;
            ok ^= cc;
            cb++;
            idx = 1;
        }else if(c == 'c'){
            if(idx > 2){
                ok = 1;
                break;
            }
            ok ^= !ca;
            ok ^= !cb;
            cc++;
            idx = 2;
        }
        if(ok)break;
    }
    if(cb == 0 || ca == 0 || cc == 0)ok = 1;
    if((cc != ca && cc != cb) || ok)cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}