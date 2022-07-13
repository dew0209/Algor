#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int main(){
    int y,k,n;cin >> y >> k >> n;
    int step = k;
    while(step < y)step = step + k;
    //cout << step << "---" << endl;
    int a0 = step - y;
    int cnt = (n - y - a0) / k;
    for(int i = 0;i <= cnt;i++){
        if(a0 + i * k >= 1)
            cout << a0 + i * k << ' ';
    }
    if(cnt == 0)cout << -1 << endl;
    
}