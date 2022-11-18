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

const int N = 5010;

int main(){
    int n,a,b;cin >> n >> a >> b;
    int res = 0;
    if(a % n == 0 || b % n == 0){
        cout << a / n + b / n << endl;
    }else {
        cout << -1 << endl;
    }
    return 0;
}