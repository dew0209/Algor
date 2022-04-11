//https://codeforces.com/problemset/problem/327/A
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[110];
int f[110];

int main(){
    int n;
    cin >> n;
    int s = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i])s++;
        a[i] = a[i] == 1 ? -1 : 1;
    }
    int res = 0;
    for(int i = 1;i <= n;i++){
        f[i] = max(a[i] + f[i - 1],a[i]);
        res = max(res,s + f[i]);
    }
    cout << res << endl;
    return 0;
}