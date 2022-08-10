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

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    while(b != d && b < 1e5){
         b < d ? b +=a : d += c;
    }
    cout << ((b == d) ? d : -1) << endl;

    return 0;
}