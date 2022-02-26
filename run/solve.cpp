#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

typedef long long LL;

using namespace std;

const int  N = 30100;

LL n,m;
LL a[N];
int cnt[N];

int main(){
    cin >> n >> m;
    int len = 0;
    while (n){
        a[len++] = n % 10;
        n /= 10;
    }
    LL maxv = 0;
    sort(a,a + len - 1);
    while (next_permutation(a,a + len - 1)){
        LL res = 0;
        for(int i = 0;i < len;i++){
            res = res * 10 + a[i];
        }
        if (res <= m){
            maxv = max(res,maxv);
        }
    }

    cout << maxv << endl;

    return 0;
}