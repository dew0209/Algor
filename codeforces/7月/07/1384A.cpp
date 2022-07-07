#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100010;

void solve(){
    int n;cin >> n;
    string s(55,'a');
    cout << s << endl;
    for(int i = 0;i < n;i++){
        int x;cin >> x;
        s[x] = s[x] == 'a' ? 'b' : 'a';
        cout << s << endl;
    }
    
}

int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}