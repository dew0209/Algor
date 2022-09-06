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

const int N = 100010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

int n,k;
string s;

int main(){
    cin >> n >> k;
    cin >> s;
    string res = "";
    int a = 0,b = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == '(' && a >= b && a < k / 2){
            res += '(';
            a++;
        }else if(b < a && b < k / 2){
            res += ')';
            b++;
        }
    }
    cout << res << endl;

    return 0;
}