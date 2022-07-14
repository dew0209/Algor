#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n,m;

int main(){
    cin >> n;
    int sumA = 0;
    int sumB = 0;
    bool ok = false;
    for(int i = 0;i < n;i++){
        int a,b;cin >> a >> b;
        if(a % 2 && b % 2 == 0){
            ok = true;
        }
        if(a % 2 == 0 && b % 2){
            ok = true;
        }
        sumA += a;
        sumB += b;
    }
    if(sumA % 2 == 0 && sumB % 2 == 0){
        cout << 0 << endl;
    }else if(sumA % 2 == 1 && sumB % 2 == 1 && ok){
        cout << 1 << endl;
    }else cout << -1 << endl;

    return 0;
}