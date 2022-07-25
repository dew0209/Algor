#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

#define fi first
#define se second

using namespace std;

const int N = 100010;

int main(){
    int n,x,y;cin >> n >> x >> y;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(x > y || a[i] <= x)sum++;
    }
    if(y >= x)sum = (sum + 1) / 2;
    cout << sum << endl;
}