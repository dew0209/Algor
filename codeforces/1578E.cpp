#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 100010;

void solve(){
    long long h,p;
    //卡cin  使用scanf
    scanf("%lld%lld",&h,&p);
    long long st = (long long)ceil(log2(p));
    if(st >= h)cout << h << endl;
    else {
        long long sumH = (long long)pow(2,h) - 1;
        long long sumK = (long long)pow(2,st) - 1;
        //cout << sumH << "debug" << sumK << endl;
        printf("%lld\n", st + ( sumH - sumK + p - 1 )/ p );
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve();
    return 0;
}