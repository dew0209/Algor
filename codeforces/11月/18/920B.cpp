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

const int N = 5010;

int n;
int q[N];

void solve(){
    int n;cin >> n;
    int c = 1;
    for(int i = 0;i < n;i++){
        int l,r;cin >> l >> r;
        if(l >= c)c = l;
        if(r < c){
            cout << "0 ";
        }else {
            cout << c << ' ';
            c++;
        }
    }
}

int main(){

    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}