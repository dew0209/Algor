#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N  = 100010;

int main(){
    int n;cin >> n;
    vector<int> res;
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        res.push_back(x);
    }
    //sort(res.begin(),res.end());
    long long ans = 0;
    for(int i = 0;i < n;i++){
        ans += abs(i + 1 - res[i]);
    }
    cout << ans << endl;
}