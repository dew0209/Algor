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
 
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    int l = 0,r = n - 1;
    while(s[l] == '<')l++;
    while(s[r] == '>')r--;
    cout << min(l,n - 1 - r);
}
 
int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
 
    return 0;
}