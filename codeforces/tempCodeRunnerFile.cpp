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
    a[0] = 1,b[0] = 1;
    for(int i = 1;i < n;i++){
        if(s[i] == '2'){
            if(a[i - 1] > b[i - 1]){
                a[i] = 0;
                b[i] = 2;
            }else if(a[i - 1] < b[i - 1]){
                a[i] = 2;
                b[i] = 0;
            }else {
                a[i] = 1;
                b[i] = 1;
            }
        }else if(s[i] == '1'){
            if(a[i - 1] > b[i - 1]){
                a[i] = 0;
                b[i] = 1;
            }else if(a[i - 1] < b[i - 1]){
                a[i] = 1;
                b[i] = 0;
            }else {
                a[i] = 0;
                b[i] = 1;
            }
        }else {
            a[i] = 0;
            b[i] = 0;
        }
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