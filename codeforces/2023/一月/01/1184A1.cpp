#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>

typedef long long LL;

using namespace std;

const int N = 100010;

int main(){
    LL r;
    cin >> r;
    if(r - 3 > 0 && (r - 3) % 2 == 0){
        cout << "1 " << (r - 3) / 2 << endl;
    }else cout << "NO" << endl;

    return 0;
}