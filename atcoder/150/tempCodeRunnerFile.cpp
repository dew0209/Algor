#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 100010;

LL n,m;
int q[N];

int get_gcd(int a,int b){
    return b ? get_gcd(b,a % b) : a;
}

int main(){
    cin >> n >> m;
    LL lcm = 1;
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        c /= 2;
        int d = get_gcd(c,lcm);
        lcm = lcm * c / d;
    }
    cout << lcm << endl;
    int cnt = m / lcm;
    if(cnt % 2 == 0){
        cnt = cnt / 2 + 1;
    }else {
        cnt = cnt / 2;
    }
    cout << cnt << endl;
    return 0;
}