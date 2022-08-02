#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long LL;

#define fi first
#define se second

using namespace std;

const int N = 200010,MOD = 1e9 + 7;

int main(){
    int n,ri;
    LL k;
    cin >> n >> k >> ri;
    int m = 0;
    for(int i = 1;i < n;i++){
        int a;cin >> a;
        if(m != k){
            if(ri > a)m++;
            else {
                ri = a;
                m = 1;
            }
        }
    }
    cout << ri << endl;
}