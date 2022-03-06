#include <iostream>
#include <cstring>

using namespace std;

string s1,s2;

int main(){
    cin >> s1 >> s2;
    string res = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for(int i = 1;i <= s1.length();i++){
        for(int j =1 ;j <= s2.length();j++){
            int ans = res.compare(s1.substr(0,i) + s2.substr(0,j));
            if(ans > 0)res = s1.substr(0,i) + s2.substr(0,j);
        }
    }
    cout << res << endl;
}