#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <numeric>

typedef long long LL;


#define fi first
#define se second

using namespace std;

const int N = 100010;

int n;
int q[N];
int a[N];
int b[N];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        int c;cin >> c;
        a[i] = c;
        if(!q[c] && c <= n){
            q[c] = 1;
            b[i] = 1;
        }
    }
    int ans = 0;
    int st = 1;
    for(int i = 1;i <= n;i++){
        if(!b[i]){
            ans++;
            while(q[st]){
                st++;
            }
            a[i] = st;
            q[st] = 1;
            b[i] = 1;
        }
    }
    for(int i = 1;i <= n;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}