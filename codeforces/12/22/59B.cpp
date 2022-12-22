#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


typedef long long LL;

using namespace std;

int res;
int sum;
int a,b;
int ma = 110,mb = 110;

int main(){
    int n;cin >> n;
    //奇数就可以了
    //偶数+奇数=奇数
    //奇数+奇数=偶数
    //奇数个奇数就行了
    for(int i = 0;i < n;i++){
        int c;cin >> c;
        sum += c;
        if(c % 2 == 1){
            a++;
            ma = min(c,ma);
        }else {
            b++;
            mb = min(c,mb);
        }
    }
    if(a && a % 2 == 0){
        sum -= ma;
    }else if(!a){
        sum = 0;
    }
    cout << sum << endl;
    return 0;
}