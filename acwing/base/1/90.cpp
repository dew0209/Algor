/*
 * A * B = A * (B)2
 *       = A * (01010101)2
 */
#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 100010;

LL qmi_add(LL a,LL b,LL p){
    LL res = 0;
    while (b){
        if(b & 1)res = (res + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return res;
}

LL a,b,p;
int main(){
    cin >> a >> b >> p;
    cout << qmi_add(a,b,p) << endl;
}