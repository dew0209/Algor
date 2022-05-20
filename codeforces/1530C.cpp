#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;

int n;
int q[N],p[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> q[i];
    for(int j = 1;j <= n;j++)cin >> p[j];
    sort(q + 1,q + 1 + n);
    sort(p + 1,p + n + 1);
    for(int i = 1;i <= n;i++){
        q[i] += q[i - 1];
        p[i] += p[i - 1];
    }
    for(int i = 0;;i++){
        int sumA = i * 100 + q[n] - q[(n + i) / 4];
        int sumB = p[n] - p[max((n + i) / 4 - i,0)];
        if(sumA < sumB)continue;
        cout << i;
        break;
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");

    return 0;
}