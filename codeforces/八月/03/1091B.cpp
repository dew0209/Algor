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

const int N = 200010,MOD = 1e9 + 7;

int main(){
    int n;cin >> n;
    LL sumX = 0,sumY = 0;
    for(int i = 0;i < 2 * n;i++){
        int x,y;cin >> x >> y;
        sumX += x;
        sumY += y;
    }
    cout << sumX / n << ' ' << sumY / n << endl;
}