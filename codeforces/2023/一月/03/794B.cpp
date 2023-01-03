#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>


typedef long long LL;

using namespace std;

const int N = 10010;

int n,m;

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n - 1;i++){
        cout << fixed << setprecision(12) << sqrt(double(i) / double(n)) * double(m);
        if(i < n - 1)cout << ' ';
    }
}