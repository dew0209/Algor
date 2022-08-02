#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7;

int main(){
    int n;string s;cin >> n >> s;
    int cnt1 = n - 11 >> 1;
    int cnt2 = cnt1;
    string res = "";
    for(int i = 0;i < n;i++){
        if(s[i] == '8'){
            if(cnt1 > 0)cnt1--;
            else res += s[i];
        }else {
            if(cnt2 > 0)cnt2--;
            else res += s[i];
        }
    }
    if(res[0] == '8')cout << "YES" << endl;
    else cout << "NO" << endl;
}