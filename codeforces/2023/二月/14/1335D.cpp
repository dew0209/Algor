#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define fi first
#define se second

#define pb push_back

typedef long long LL;

const int N = 100010;

using namespace std;

string s[10];

void solve(){
    for(int i = 0;i < 9;i++)cin >> s[i];
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            if(s[i][j] == '2')s[i][j] = '1';
        }
    }
    for(int i = 0;i < 9;i++){
        for(int j = 0;j < 9;j++){
            cout << s[i][j];
        }
        cout << endl;
    }
}

int main(){
    int n;cin >> n;
    while(n--)solve();
    return 0;
}