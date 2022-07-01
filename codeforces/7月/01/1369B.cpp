//https://codeforces.com/contest/1369/problem/B
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;

void solve(){
    cin >> n;
    string s;cin >> s;
    int l = -1;
    int r = n;
    int a = 0;
    int b = 0;
    while(l + 1 < n && s[l + 1] == '0'){
        l++;
        a++;
    }

    while(r - 1 >= 0 && s[r - 1] == '1'){
        r--;
        b++;
    }

    if(a + b < n){
        a++;
        for(int i = 1;i <= a;i++)cout << '0';
        for(int i = 1;i <= b;i++)cout << '1';
    }else {
        cout << s;
    }
    
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}