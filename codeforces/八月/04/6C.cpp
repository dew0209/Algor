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

int n;
int q[N];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> q[i];
    int l = 1,r = n;
    int sumL = q[1],sumR = q[n];
    while(l <= r){
        if(sumL <= sumR)sumL += q[++l];
        else sumR += q[--r];
    }
    cout << (l - 1) << ' ' << (n - r) << endl;

    return 0;
}