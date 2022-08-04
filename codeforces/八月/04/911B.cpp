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

int a,b,c;

int main(){
   cin >> a >> b >> c;
   int res = 0;
   for(int i = 1;i < a;i++){
     res = max(min(b / i,c / (a - i)),res);
   }
   cout << res << endl;
}