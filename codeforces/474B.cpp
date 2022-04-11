//https://codeforces.com/problemset/problem/474/B   暴力模拟
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;

int n,m;
int a[N],b[N];
int ans[N];
int cnt[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i];
    cin >> m;
    for(int i = 1;i <= m;i++)cin >> b[i];
    int st = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= a[i];j++){
            cnt[j + st] = i;
        }
        st = a[i] + st;
    }
    for(int i = 1;i <= m;i++){
        cout << cnt[b[i]] << endl;
    }
    return 0;
}