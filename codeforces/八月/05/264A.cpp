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

int main(){
    string s;cin >> s;
    for(int i = 0;i < s.length();i++){
        if(s[i] == 'r')cout << i + 1 << ' ';
    }

    for(int i = s.size() - 1;i >= 0;i--){
        if(s[i] == 'l')cout << i + 1 << ' ';
    }
}