#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

typedef long long LL;

using namespace std;

const int N = 200010;

int main(){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a,b;cin >> a >> b;
    int absx = abs(x1 - x2);
    int absy = abs(y1 - y2);
    bool ok = 1;
    if(absx % a == 0 && absy % b == 0 && absx / a % 2 == 1 && absy / b % 2 == 1){
        ok = 1;
    }else if(absx % a == 0 && absy % b == 0 && absx / a % 2 == 0 && absy / b % 2 == 0){
        ok = 1;
    }else ok = 0;
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}