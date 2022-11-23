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

int q[N];


int main(){
    int n,m;
    while(m--){
        int a,b;cin >> a >> b;
        q[b]++;
        q[a]++;
    }
    int sum0 = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sumn = 0;
    for(int i = 1;i <= n;i++){
        if(q[i] == 1){
            sum1++;
        }else if(q[i] == 0){
            sum0++;
        }else if(q[i] == 2){
            sum2++;
        }else if(q[i] == n){
            sumn++;
        }
    }
    if(sum1 + sum2 == n && sum1 == 2){
        cout << "bus topology" << endl;
    }else if(sum2 == n){
        cout << "ring topology" << endl;
    }else if(sum1 == n - 1 && sumn == 1){
        cout << "star topology" << endl;
    }else {
        cout << "unknown topology" << endl;
    }
    return 0;
}