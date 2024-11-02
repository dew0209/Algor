#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

#define x first
#define y second

using namespace std;

typedef long long LL;

const int N = 110;

int n,m;
int q[N],r[N];

int main(){
    
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> q[i] >> r[i];

    cin >> m;
    for(int i = 1;i <= m;i++){
        
        int tj,di;cin >> tj >> di;

        int ans = (di - r[tj] + q[tj] - 1) / q[tj];
        cout << (LL)(ans) * q[tj] + r[tj] << endl;
    }

}