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

map<string,bool> cnt;

int main(){
    int n;cin >> n;
    string s[n];
    for(int i = 0;i < n;i++){
        cin >> s[i];
    }
    for(int i = n - 1;i >= 0;i--){
        if(!cnt[s[i]]){
            cout << s[i] << endl;
            cnt[s[i]] = true;
        }
    }
    return 0;
}