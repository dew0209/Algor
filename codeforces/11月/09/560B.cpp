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

int a[2],ax[2];
int b[2],ay[2];
int c[2],az[2];

int main(){
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    cin >> c[0] >> c[1];
    ax[0] = ay[0] = az[0] = 0;
    ax[1] = ay[1] = az[1] = 1;
    do{
        do{
            do{
                int x = max(b[ay[0]],c[az[0]]);
                int y = b[ay[1]] + c[az[1]];
                if(x <= a[ax[0]] && y <= a[ax[1]]){
                    cout << "Yes" << endl;
                    return 0;
                }
            }while(next_permutation(az,az + 2));
        }while(next_permutation(ay,ay + 2));
    }while(next_permutation(ax,ax + 2));
    cout << "No" << endl;
    return 0;
}