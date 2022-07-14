#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

int n;
int a[3010];

int main(){
    int n;cin >> n;
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        a[x] = 1;
    }
    int res = 0;
    for(int i = 1;i <= 30001;i++){
        if(!a[i]){
            res = i;
            break;
        }
    }
    cout << res << endl;
}