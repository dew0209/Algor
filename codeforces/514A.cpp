//https://codeforces.com/problemset/problem/514/A

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n,m;
long long a[30];

int main(){
    long long k;cin >> k;
    int idx = 0;
    while(k){
        a[idx++] = k % 10;
        k /= 10;
    }
    
    for(int i = idx - 1;i >= 0;i--){
        
        if(a[i] > 9 - a[i]){
            if(i == idx - 1 && a[i] == 9)continue;
            a[i] = 9 - a[i];
        }
    }
    
    int j = idx - 1;
    while(j >= 0 && a[j] == 0){
        j--;
    }
    if(j < 0)cout << 0;
    for(int i = j;i >= 0;i--){
        cout << a[i];
    }
    cout << endl;

    return 0;
}