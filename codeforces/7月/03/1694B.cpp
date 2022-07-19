#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;

int n;
string s;

void solve(){
    cin >> n >> s;
    long long ans = n;
    for(int i = 1;i < n;i++){
        if(s[i] != s[i - 1])ans += i;
    }
    cout << ans;
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}