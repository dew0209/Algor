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

int main(){
    int n,k;cin >> n >> k;
    k--;
    int l = 1,r = n;
    int b = 1;
    while(l <= r){
        if(b)cout << l++ << ' ';
        else cout << r-- << ' ';
        if(k)b ^= 1,k--;
    }
    cout << endl;
}