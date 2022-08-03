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
//a->b
int n,a,b;

int main(){
    cin >> n >> a >> b;
    string s;cin >> s;
    a--,b--;
    cout << ((s[a] - '0') ^ (s[b] - '0')) << endl;
}