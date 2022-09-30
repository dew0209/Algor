#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int main(){
    string s;cin >> s;
    int total = 0;
    for(int i = 0;i < s.size();i++){
        bool ok = false;
        for(int j = i + 3;j < s.size();j++){
            if(ok) ;
            else{
                ok = s[j - 3] == 'b' && s[j - 2] == 'e' && s[j - 1] == 'a' && s[j] == 'r';
            }
            total += ok;
        }
    }
    cout << total << endl;
}