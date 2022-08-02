#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define fi first
#define se second

using namespace std;
const int N = 200010,MOD = 1e9 + 7;


int q[N];

int main(){
    int n;cin >> n;
    int preOdd = 0;
    int preEven = 0;
    int ans = 0;
    int sumOdd = 0;
    int sumEven = 0;
    for(int i = 1;i <= n;i++){
        cin >> q[i];
        if(i % 2 == 1)sumOdd += q[i];
        else sumEven += q[i];
    }
    for(int i = 1;i <= n;i++){
        if(i % 2 == 1){
            sumOdd -= q[i];
            if(sumOdd + preEven == sumEven + preOdd){
                ans++;
            }
            preOdd += q[i];
        }else {
            sumEven -= q[i];
            if(sumOdd + preEven == sumEven + preOdd){
                ans++;
            }
            preEven += q[i];
        }
        
    }
    cout << ans << endl;
}