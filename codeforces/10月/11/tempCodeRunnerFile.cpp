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

const int N = 1000010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int main(){
    string s;cin >> s;
    LL res = 0;
    string ans = "";
    for(int i = 0;i < s.size();i++){
        //">"  →  1000,
        if(s[i] == '>')ans += "1000";
        //"<"  →  1001,
        if(s[i] == '<')ans += "1001";
        //"+"  →  1010,
        if(s[i] == '+')ans += "1010";
        //"-"  →  1011,
        if(s[i] == '-')ans += "1011";
        //"."  →  1100,
        if(s[i] == '.')ans += "1100";
        //","  →  1101,
        if(s[i] == ',')ans += "1101";
        //"["  →  1110,
        if(s[i] == '[')ans += "1110";
        //"]"  →  1111.
        if(s[i] == ']')ans += "1111";
    }
    int st = 1;
    for(int i = ans.size() - 1;i >= 0;i--){
        res += (ans[i] - '0') * st;
        st *= 2;
        res %= 1000003;
    }
    cout << res << endl;
    return 0;
}