#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int N = 200010;

int main(){
    LL n;cin >> n;
    LL res = 0;
    LL st = 1;
    while(n - st >= 0){
        res += n - st + 1;
        st *= 10;
    }
    cout << res << endl;
}