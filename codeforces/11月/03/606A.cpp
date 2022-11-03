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

int main(){
    int x,y,z;cin >> x >> y >> z;
    int a,b,c;cin >> a >> b >> c;
    int dx = x - a,dy = y - b,dz = z - c;
    
    int res = 0;
    if(dx > 0){
        res += dx / 2;
    }
    if(dy > 0){
        res += dy / 2;
    }
    if(dz > 0){
        res += dz / 2;
    }

    int ans = 0;
    if(dx < 0){
        ans -= dx;
    }
    if(dy < 0){
        ans -= dy;
    }
    if(dz < 0){
        ans -= dz;
    }

    if(res >= ans){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }

    return 0;
}