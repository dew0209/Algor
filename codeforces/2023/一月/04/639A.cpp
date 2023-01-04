#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>

using namespace std;

const int N = 200010;

int n,k,p;
int st[N];
int q[N];

int main(){
    cin >> n >> k >> p;
    for(int i = 1;i <= n;i++)cin >> q[i];
    set<int> res;
    while(p--){
        int a,b;cin >> a >> b;
        if(a == 1){
            res.insert(q[b]);
            if(res.size() > k)res.erase(*res.begin());
        }else {
            if(res.find(q[b]) == res.end()){
                cout << "NO" << endl;
            }else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}