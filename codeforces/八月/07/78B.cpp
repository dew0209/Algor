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

int n;
string color = "ROYGBIV";
string ans[7] = {"","G","GB","YGB","YGBI","OYGBI","OYGBIV"};

int main(){
    cin >> n;
    int cnt = n / 7;
    for(int i = 0;i < cnt;i++){
        cout << color;
    }
    cout << ans[n % 7];
    cout << endl;
}