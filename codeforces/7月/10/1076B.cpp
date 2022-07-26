#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define fi first
#define se second

typedef long long LL;

using namespace std;

const int N = 100010;

LL get(LL u){
    for(int i = 2;i <= u / i;i++){
        if(u % i == 0)return i;
    }
    return u;
}

int main(){
    LL n;cin >> n;
    LL cnt = 0;
    if(n % 2){
        n -= get(n);
        //cout << n << endl;
        cnt++;
    }
    cout << cnt + n / 2 << endl;
}