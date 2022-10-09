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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int k;

int main(){
    cin >> k;
    if(k > 36)cout << "-1" << endl;
    else {
        while(k > 0){
            if(k >= 2){
                cout << "8";
                k -= 2;
            }else {
                cout << "9";
                k--;
            }
        }
        cout << endl;
    }
    return 0;
}