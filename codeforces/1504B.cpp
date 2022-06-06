#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
int n;
    string a,b;cin >> n >> a >> b;
    a.push_back('0');
    b.push_back('0');
    int cnt = 0;
    for(int i = 0;i < n;i++){
        cnt += (a[i] == '1') - (a[i] == '0');
        if((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && cnt != 0){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main(){
    int T;cin >> T;
    while(T--)solve(),puts("");
}