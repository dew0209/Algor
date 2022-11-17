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

int q[310];

int main(){
    int n;cin >> n;
    for(int i = 0;i < n;i++){
        cin >> q[i];
    }
    string res = "";
    for(int i = 0;i < n;i++){
        while(q[i]){
            if(i != n - 1){
                res += "RLP";
            }else {
                res += "LRP";
            }
            q[i--];
        }
        if(i != n - 1){
            res += "R";
        }
    }
}