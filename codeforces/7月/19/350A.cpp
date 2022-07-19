#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;

int main(){
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        a.push_back(x);
    }
    for(int i = 0;i < m;i++){
        int x;cin >> x;
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int res = max(a[0] * 2,a[n - 1]);
    if(res >= b[0])res = -1;
    cout << res << endl;
}