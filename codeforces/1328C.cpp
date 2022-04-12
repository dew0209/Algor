//https://codeforces.com/problemset/problem/1328/C

#include <iostream>
#include <cstring>

using namespace std;

const int N = 500010;

int n,m;
int a[N],b[N];

void solve(){
    cin >> n;
    string s;cin >> s;
    for(int i = 1;i < n;i++)a[i] = b[i] = 0;
    a[0] = 1,b[0] = 1;
    for(int i = 1;i < n;i++){
        if(s[i] == '1'){
            a[i] = 1;
            b[i] = 0;
            for(int j = i + 1;j < n;j++)b[j] = s[j] - '0';
            break;
        }else a[i] = b[i] = (s[i] - '0' ) / 2;
    }
    for(int i = 0;i < n;i++)cout << a[i];
    cout << endl;
    for(int i = 0;i < n;i++)cout << b[i];
    cout << endl;

}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}