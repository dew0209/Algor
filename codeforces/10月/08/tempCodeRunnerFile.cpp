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


int n;
int q[N];

int main(){
    cin >> n;
    int maxV = 0;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        if(x > maxV){
            cnt = 1;
            maxV = x;
        }else if(x == maxV){
            cnt++;
        }
    }
    if(cnt % 2){
        cout << "Conan" << endl;
    }else cout << "Agasa" << endl;
}