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

const int N = 1010;

int get_gcd(int a,int b){
    return b ? get_gcd(b,a % b) : a;
}

int main(){
    int a,b,c,d;cin >> a >> b >> c >> d;
    LL min = 1LL * a * b / get_gcd(a,b);
    //cout << min << endl;
    cout << d / min - (c - 1) / min << endl;
    return 0;
}