#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>

typedef long long LL;

using namespace std;

int main(){
    string s;cin >> s;
    LL a = 0;
    for(int i = 0;i < s.size() - 1;i++){
        a = a * 10 + (s[i] - '0');
    }
    LL r = a % 4;
    LL cnt = (a - 1) / 4;
    LL res = 0;
    res = res + 16 * cnt;
    if(r == 0 || r == 2){
        res += 7;
    }
    if(s[s.size() - 1] == 'a')res += 4;
    if(s[s.size() - 1] == 'b')res += 5;
    if(s[s.size() - 1] == 'c')res += 6;
    if(s[s.size() - 1] == 'd')res += 3;
    if(s[s.size() - 1] == 'e')res += 2;
    if(s[s.size() - 1] == 'f')res += 1;
    cout << res << endl;
    return 0;
}