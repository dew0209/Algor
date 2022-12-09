#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 100010;

LL n,m;
int q[N];

LL get_gcd(LL a,LL b){
    return b ? get_gcd(b,a % b) : a;
}

int main(){
    cin >> n >> m;
    LL lcm = 1;
    for(int i = 0;i < n;i++){
        cin >> q[i];
        int c = q[i];
        c /= 2;
        LL d = get_gcd(c,lcm);
        lcm = lcm * c / d;
    }
    for(int i = 0;i < n;i++){
        if((lcm / (q[i] / 2)) % 2 == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    int cnt = m / lcm;
    if(cnt % 2 == 0){
        cnt = cnt / 2;
    }else {
        cnt = cnt / 2 + 1;
    }
    cout << cnt << endl;
    return 0;
}