#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

#define x first
#define y second

using namespace std;

typedef long long LL;

const int N = 200010;

int n,m;
int a[N];
int res[N];
map<int,int> cnt;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];

    for(int i = 1;i <= n;i++){
        int v = a[i];
        if(cnt.count(v)){
            res[i] = cnt[v];
        }else {
            res[i] = -1;
        }
        cnt[v] = i;
    }
    for(int i = 1;i <= n;i++){
        cout << res[i] << ' ';
    }
    cout << endl;
}