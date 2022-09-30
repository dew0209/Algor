#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 10010,MOD = 1e9 + 7,INF = 0x3f3f3f3f;

string s;

bool ok(string t){
    int msk = 0;
    for(int i = 0;i < t.size();i++){
        if(isupper(t[i]))msk |= 1;
        if(islower(t[i]))msk |= 2;
        if(isdigit(t[i]))msk |= 4;
    }
    return msk == 7;
}

void solve(){
    cin >> s;
    bool flag = 0;
    if(ok(s)){
        cout << s;
        return;
    }
    for(int i = 0;i < s.size();i++){
        string t = s;
        t[i] = '1';
        if(ok(t)){
            cout << t;
            flag = 1;
            break;
        }
        t[i] = 'a';
        if(ok(t)){
            cout << t;
            flag = 1;
            break;
        }
        t[i] = 'A';
        if(ok(t)){
            cout << t;
            flag = 1;
            break;
        }
    }
    if(flag)return;
    if(isupper(s[2])){
        s[0] = 'a';
        s[1] = '1';
        cout << s;
        return;
    }
    if(islower(s[2])){
        s[0] = 'A';
        s[1] = '1';
        cout << s;
        return;
    }
    if(isdigit(s[2])){
        s[0] = 'a';
        s[1] = 'A';
        cout << s;
        return;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}