#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;

void solve(){
    cin >> n;
    string s;cin >> s;
    int sum = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == '0')sum++;
    }
    if(sum % 2 == 0 || sum == 1)cout << "BOB";
    else cout << "ALICE";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}