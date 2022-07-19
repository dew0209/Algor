#include <iostream>
#include <cstring>
#include <algorithm>
 
typedef long long LL;
 
using namespace std;
 
const int N = 300010;
 
int n;
LL q[N];
 
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> q[i];
    sort(q + 1,q + n + 1);
    for(int i = 1;i <= n;i++){
        q[i] += q[i - 1];
    }
    LL res = q[n];
    for(int i = 1;i < n;i++){
        res += q[n] - q[i - 1];
    }
    cout << res << endl;
}