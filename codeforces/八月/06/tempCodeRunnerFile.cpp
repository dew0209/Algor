#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7;

int main(){
    LL n;
    cin >> n;
    LL res = 0;
    for(int i = 1;i <= n / i;i++){
        if(n % i == 0){
            res++;
            if(n / i != i)res++;
        }
        
    }
    cout << res << endl;
}