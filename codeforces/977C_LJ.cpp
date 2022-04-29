#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int N = 100010;

int n,m;

int main(){
    cin >> n >> m;
    vector<int> a(n);
    int res = 0;
    for(int i  = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(m == 0){
        res = a[0] - 1;
    }else res = a[m - 1];
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if(a[i] <= res)cnt++;
    }
    if(cnt != m || res < 1)res = -1;
    cout << res << endl;
    return 0;
}