//https://codeforces.com/problemset/problem/474/B  二分

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;
int a[N];

int getRes(int u){
    int l = 1,r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(a[mid] >= u)r = mid;
        else l = mid + 1;
    }
    return r;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> a[i],a[i] += a[i - 1];
    int m;cin >> m;
    for(int i = 1;i <= m;i++){
        int b;cin >> b;
        cout << getRes(b) << endl;
    }
    return 0;
}