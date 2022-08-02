#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;

const int N = 100010,MOD = 1e9 + 7;

int n,m;
int q[N];

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++)cin >> q[i];
    while(m--){
        int c;cin >> c;
        int l = 0,r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(q[mid] >= c)r = mid;
            else l = mid + 1;
        }
        if(q[l] != c)cout << "-1 -1" << endl;
        else {
            cout << l << ' ';
            l = 0,r = n - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(q[mid] <= c)l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}