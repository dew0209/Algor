#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

void build(int l,int r,vector<int> const &a,vector<int> &d,int curD){
    if(r < l){
        return;
    }
    if(l == r){
        d[l] = curD;
        return;
    }
    int m = l;
    for(int i = l + 1;i <= r;i++){
        if(a[m] < a[i])m = i;
    }
    d[m] = curD;
    build(l, m - 1,a,d,curD + 1);
    build(m + 1, r,a,d,curD + 1);

}

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++)cin >> a[i];
    vector<int> d(n);
    build(0,n - 1,a,d,0);
    for(int x : d){
        cout << x << ' ';
    }
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
    return 0;
}