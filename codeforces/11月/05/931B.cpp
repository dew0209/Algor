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

const int N = 100010;

int main(){
    int n,a,b;cin >> n >> a >> b;
    a--;b--;
    int ans = 0;
    while(true){
        ans++;
        a = a / 2;
        b = b / 2;
        n = n / 2;
        if(a == b && n == 1){
            cout << "Final!" << endl;
            return 0;
        }
        if(a == b){
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}