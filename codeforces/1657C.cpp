#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n,m;

void solve(){
    cin >> n;
    string s;cin >> s;
    //回文或者是正确的括号序列， ))  ()
    int a = 0,b = 0;
    bool ok = false;
    int ans = 0;
    int temp = n;
    for(int i = 0;i < n;i++){
        if(s[i] == '('){
            i++;
            if(n - i + 1 >= 2)temp -= 2,ans++;
            //cout << "1test" << endl;
        }else {
            int j = i + 1;
            while (j < n && s[j] != ')'){
                j++;
            }
            if(j < n){
                int len = j - i + 1;
                ans++;
                temp -= len;
                i = j;
            }else break;
            //cout << "2test" << endl;
        }
    }
    cout << ans << ' ' << temp << endl;
}


int main(){
    int T;cin >> T;
    while(T--)solve();

    return 0;
}