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

void solve(){
    int n,m;
    cin >> n >> m;
    int k = 1;
    //首先保证至少一个2一个5
    int a = 0;
    while(n % 2 == 0){
        a++;
        n /= 2;
    }
    int b = 0;
    while(n % 5 == 0){
        n /= 5;
        b++;
    }
    while(k < m){
        int tmp = k;
        if(a < b){
                if(k * 2 < m){
                    k = k * 2;
                    a++;
                }
                if(k * 5 < m){
                    k = k * 5;
                    b++;
                }
        }else {
            if(k * 5 < m){
                    k = k * 5;
                    b++;
            }
            if(k * 2 < m){
                    k = k * 2;
                    a++;
            }
        }

        if(tmp == k)break;
    }
    bool ok1 = n % 2 == 0 || k % 2 == 0;
    bool ok2 = n % 5 == 0 || k % 5 == 0;
    if(ok1 && ok2){
        cout << 1LL * n * pow(2,a) * pow(5,b);
    }else {
        cout << 1LL * n * m;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}