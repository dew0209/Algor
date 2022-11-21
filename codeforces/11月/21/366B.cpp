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

const int N = 200010;

int n,k;
int q[N];

int main(){
    cin >> n >> k;
    for(int i = 0;i < n;i++){
        int t;cin >> t;
        q[i % k] += t;
    }
    int m = 0;
    for(int i = 1;i < k;i++){
        if(q[i] < q[m]){
            m = i;
        }
    }
    cout << m + 1 << endl;
    return 0;
}