//https://codeforces.com/problemset/problem/433/B
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N],b[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i],b[i] = a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }
    int T;cin >> T;
    while(T--){
        int x,y,z;cin >> x >> y >> z;
        if(x == 1)cout << b[z] - b[y - 1] << endl;
        else cout << a[z] - a[y - 1] << endl;
    }
    return 0;
}